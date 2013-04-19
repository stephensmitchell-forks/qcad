/**
 * Copyright (c) 2011-2013 by Andrew Mustun. All rights reserved.
 * 
 * This file is part of the QCAD project.
 *
 * QCAD is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QCAD is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QCAD.
 */
#include <QFont>
#include <QFontMetricsF>
#include <QTextBlock>
#include <QTextDocument>

#include "RColor.h"
#include "RFont.h"
#include "RFontList.h"
#include "RTextData.h"
#include "RPainterPathDevice.h"
#include "RPointEntity.h"
#include "RPolyline.h"
#include "RSettings.h"
#include "RTextRenderer.h"


RTextData::RTextData()
 : textHeight(0.0),
   textWidth(0.0),
   verticalAlignment(RS::VAlignTop),
   horizontalAlignment(RS::HAlignLeft),
   drawingDirection(RS::LeftToRight),
   lineSpacingStyle(RS::Exact),
   lineSpacingFactor(1.0),
   fontName("standard"),
   bold(false),
   italic(false),
   angle(0.0),
   simple(false),
   height(RNANDOUBLE), width(RNANDOUBLE), dirty(true), gotDraft(false) {
}

RTextData::RTextData(RDocument* document, const RTextData& data)
    : REntityData(document) {
    *this = data;
    this->document = document;
    if (document!=NULL) {
        linetypeId = document->getLinetypeByLayerId();
    }
}

/**
 * \param position Insertion point (see DXF code 10 doc).
 * \param alignmentPoint Alignement point of text (see DXF code 11 doc).
 * \param height Nominal (initial) text height
 * \param textWidth Reference rectangle width for wrapping (not supported)
 * \param valign Vertical alignment
 * \param halign Horizontal alignment
 * \param drawingDirection Drawing direction
 * \param lineSpacingStyle Line spacing style
 * \param lineSpacingFactor Line spacing factor
 * \param text Text string
 * \param fontName Text font name
 * \param angle Rotation angle in rad
 */
RTextData::RTextData(const RVector& position,
                     const RVector& alignmentPoint,
                     double height,
                     double textWidth,
                     RS::VAlign valign,
                     RS::HAlign halign,
                     RS::TextDrawingDirection drawingDirection,
                     RS::TextLineSpacingStyle lineSpacingStyle,
                     double lineSpacingFactor,
                     const QString& text,
                     const QString& fontName,
                     bool bold,
                     bool italic,
                     double angle,
                     bool simple)
    : position(position),
      alignmentPoint(alignmentPoint),
      textHeight(height),
      textWidth(textWidth),
      verticalAlignment(valign),
      horizontalAlignment(halign),
      drawingDirection(drawingDirection),
      lineSpacingStyle(lineSpacingStyle),
      lineSpacingFactor(lineSpacingFactor),
      fontName(fontName),
      bold(bold),
      italic(italic),
      angle(angle),
      simple(simple),
      height(RNANDOUBLE), width(RNANDOUBLE),
      dirty(true), gotDraft(false) {

    setText(text);
}

RBox RTextData::getBoundingBox() const {
    if (!boundingBox.isValid() || dirty) {
        getPainterPaths(gotDraft);
    }

    return boundingBox;
}

/**
 * Width of the text (this is not equal to the bounding box width as it is
 * the width of the text at 0 angle).
 */
double RTextData::getWidth() const {
    if (RMath::isNaN(width) || dirty) {
        getPainterPaths(gotDraft);
    }

    return width;
}

/**
 * Height of the text (this is not equal to the bounding box height as it is
 * the height of the text at 0 angle).
 */
double RTextData::getHeight() const {
    if (RMath::isNaN(height) || dirty) {
        getPainterPaths(gotDraft);
    }

    return height;
}

RVector RTextData::getPointOnEntity() const {
    if (painterPaths.size()==0) {
        return RVector::invalid;
    }

    RPainterPath path = painterPaths.at(0);
    QPointF p = path.pointAtPercent(0.0);
    return RVector(p.x(), p.y());
}

double RTextData::getDistanceTo(const RVector& point, bool limited, double range, bool draft) const {
    Q_UNUSED(limited)
    Q_UNUSED(draft)
    
    if (!getBoundingBox().grow(range).contains(point)) {
        //qDebug() << "RTextData::getDistanceTo: bounding box not in range: " << getBoundingBox();
        return RNANDOUBLE;
    }

    if (painterPaths.size()==0) {
        qDebug() << "RTextData::getDistanceTo: no painter paths";
    }

    //qDebug() << "painterPaths: " << painterPaths.size();
    double ret = RNANDOUBLE;

    for (int i=0; i<painterPaths.size(); ++i) {
        RPainterPath path = painterPaths.at(i);

        // path is not filled (outline or CAD font):
        if (path.getBrush()==Qt::NoBrush) {
            double d = path.getDistanceTo(point);
            if (RMath::isNaN(ret) || d<ret) {
                ret = d;
            }
        }

        // path is filled:
        else {
            // speed optimization for complex glyphs (probably not needed):
            //int elementCount = path.elementCount();
            //if (elementCount>200 && path.boundingRect().contains(QPointF(point.x, point.y))) {
            //    return range;
            //}

            // simple characters, exact:
            if (path.contains(QPointF(point.x, point.y))) {
                if (RMath::isNaN(ret) || range<ret) {
                    // position on top of character, it doesn't get better than that:
                    ret = range/2.0;
                    break;
                }
            }
            else if (path.getBoundingBox().contains(point)) {
                QList<QPolygonF> subPaths = path.toSubpathPolygons();
                for (int k=0; k<subPaths.size(); k++) {
                    QPolygonF polygon = subPaths.at(k);
                    RBox bb = RBox(polygon.boundingRect());
                    if (bb.contains(point)) {
                        // still a chance for a closer match:
                        ret = range;
                    }
                }
            }
        }

    }

    return ret;
}

bool RTextData::intersectsWith(const RShape& shape) const {
    const RPolyline* polyline = dynamic_cast<const RPolyline*>(&shape);
    if (polyline==NULL) {
        return false;
    }

    QPainterPath polylinePath = polyline->toPainterPath();

    QPainterPath combinedPath;
    for (int i=0; i<painterPaths.size(); ++i) {
        RPainterPath path = painterPaths.at(i);
        combinedPath.addPath(path);
    }

    if (polylinePath.intersects(combinedPath) &&
        !polylinePath.contains(combinedPath)) {

        return true;
    }

    return false;
}

void RTextData::setText(const QString& text) {
    this->text = text;
    update();
}

QList<RVector> RTextData::getReferencePoints(
        RS::ProjectionRenderingHint hint) const {
    Q_UNUSED(hint)

    QList<RVector> ret;

    ret.append(alignmentPoint);

    /*
    if (!simple) {
        if (height<1.0e-6 || dirty) {
            getPainterPaths();
        }

        RVector vWidth = RVector::createPolar(textWidth, angle);
        RVector vHeight = RVector::createPolar(height, angle);

        ret.append(position + vWidth);
        ret.append(position + vWidth + vHeight);
        ret.append(position + vHeight);
    }
    */

    return ret;
}

bool RTextData::moveReferencePoint(const RVector& referencePoint,
        const RVector& targetPoint) {
    bool ret = false;
    if (referencePoint.getDistanceTo(position) < RS::PointTolerance) {
        position = targetPoint;
        ret = true;
        update();
    }
    return ret;
}

bool RTextData::move(const RVector& offset) {
    position.move(offset);
    alignmentPoint.move(offset);
    update();
    return true;
}

bool RTextData::rotate(double rotation, const RVector& center) {
    position.rotate(rotation, center);
    alignmentPoint.rotate(rotation, center);
    angle = RMath::getNormalizedAngle(angle+rotation);
    update();
    return true;
}

bool RTextData::scale(const RVector& scaleFactors, const RVector& center) {
    position.scale(scaleFactors, center);
    alignmentPoint.scale(scaleFactors, center);
    textWidth*=scaleFactors.x;
    textHeight*=scaleFactors.x;
    update();
    return true;
}

bool RTextData::mirror(const RLine& axis) {
    position.mirror(axis);
    alignmentPoint.mirror(axis);
    bool readable = RMath::isAngleReadable(angle);

    RVector vec = RVector::createPolar(1.0, angle);
    vec.mirror(RVector(0.0,0.0), axis.getEndPoint()-axis.getStartPoint());
    angle = vec.getAngle();

    bool corr;
    angle = RMath::makeAngleReadable(angle, readable, &corr);

    if (corr) {
        if (horizontalAlignment==RS::HAlignLeft) {
            horizontalAlignment=RS::HAlignRight;
        } else if (horizontalAlignment==RS::HAlignRight) {
            horizontalAlignment=RS::HAlignLeft;
        }
    } else {
        if (verticalAlignment==RS::VAlignTop) {
            verticalAlignment=RS::VAlignBottom;
        } else if (verticalAlignment==RS::VAlignBottom) {
            verticalAlignment=RS::VAlignTop;
        }
    }
    update();
    return true;
}

bool RTextData::flipHorizontal() {
    return mirror(RLine(RVector(0,0), RVector(0,1)));
}

bool RTextData::flipVertical() {
    return mirror(RLine(RVector(0,0), RVector(1,0)));
}

QFont RTextData::getMainFont() const {
    QFont mainFont(fontName);
    mainFont.setPointSizeF(textHeight);
    return mainFont;
}

QString RTextData::getPlainText() const {
    QTextDocument td;
    td.setHtml(toRichText(text, getMainFont()));
    return td.toPlainText();
}

QString RTextData::getEscapedText() const {
    return text;
}

// "lo\C4;\H2.5;rem\P\C1;\fBaskerville|b0|i0|c0|p34;backslash:\FAPNORM.SHX|c0;\\semicolon:;\Pdolor\Psit\~amet\Plorem \Sipsum/dolor; sit\~amet"
QList<RPainterPath> RTextData::getPainterPaths(bool draft) const {
    if (!dirty) {
        // cached painter paths represent text in current draft mode (draft or normal):
        if (draft==gotDraft) {
            return painterPaths;
        }
    }

    // render text into painter paths:
    RTextRenderer renderer(*this, draft, RTextRenderer::PainterPaths);
    painterPaths = renderer.getPainterPaths();
    boundingBox = renderer.getBoundingBox();
    //qDebug() << "RTextData::getPainterPaths: boundingBox: " << boundingBox;
    height = renderer.getHeight();
    width = renderer.getWidth();

    dirty = false;
    gotDraft = draft;
    return painterPaths;
}

RVector RTextData::getClosestPointOnEntity(const RVector& point,
    double range, bool limited) const {

    Q_UNUSED(point);
    Q_UNUSED(range);
    Q_UNUSED(limited);

    return RVector::invalid;
}

QList<QSharedPointer<RShape> > RTextData::getShapes(const RBox& queryBox) const {
    Q_UNUSED(queryBox);

    return QList<QSharedPointer<RShape> >();
}

QList<QSharedPointer<RShape> > RTextData::getExploded() const {
    QList<QSharedPointer<RShape> > shapes;

    QList<RPainterPath> paths = getPainterPaths();
    for (int i=0; i<paths.length(); i++) {
        RPainterPath path = paths[i];
        shapes.append(path.getShapes());
    }

    return shapes;
}

void RTextData::update() const {
    dirty = true;
    boundingBox = RBox();
    painterPaths.clear();
}

bool RTextData::isDirty() const {
    return dirty;
}

/**
 * Converts the given text document (typically from a QTextEdit) into
 * CAD escaped text.
 *
 * \param fontHeightFactor factor applied to all font heights. This allows
 *      the text edit to use a bigger / smaller font that needed in the end.
 */
QString RTextData::toEscapedText(const QTextDocument& textDocument, const RColor& initialColor, double fontHeightFactor) {
    QString ret = "";

    QString fontFamily = textDocument.defaultFont().family();
    int fontWeight = textDocument.defaultFont().weight();
    bool fontItalic = textDocument.defaultFont().italic();
    double fontHeight = textDocument.defaultFont().pointSizeF() / fontHeightFactor;
    QTextCharFormat::VerticalAlignment fontVerticalAlignment = QTextCharFormat::AlignNormal;
    QTextCharFormat::VerticalAlignment previousVerticalAlignment = QTextCharFormat::AlignNormal;
    // initial color is color of entity:
    RColor fontColor = initialColor;
    int blockCounter = 0;

    //qDebug() << "RTextData::toEscapedText: html: " << textDocument.toHtml();

    //qDebug() << "initialColor: " << initialColor;

    for (QTextBlock block = textDocument.firstBlock(); block.isValid(); block = block.next()) {
        // new paragraph:
        if (blockCounter!=0) {
            ret += "\\P";
        }

        //qDebug() << "text block: " << blockCounter;

        blockCounter++;

        QTextBlock::iterator it;
        for (it=block.begin(); it!=block.end(); ++it) {
            QTextFragment fragment = it.fragment();
            if (!fragment.isValid()) {
                continue;
            }

            //qDebug() << "text fragment: " << fragment.text();

            bool fontChanged = false;
            bool colorChanged = false;
            bool heightChanged = false;
            bool verticalAlignmentChanged = false;

            QTextCharFormat format = fragment.charFormat();

            // detect font weight change (bold):
            if (format.fontWeight()!=fontWeight) {
                fontWeight = format.fontWeight();
                fontChanged = true;
            }

            // detect italic change:
            if (format.fontItalic()!=fontItalic) {
                fontItalic = format.fontItalic();
                fontChanged = true;
            }

            // detect vertical alignment change (subscript / superscript):
            if (format.verticalAlignment()!=fontVerticalAlignment) {
                previousVerticalAlignment = fontVerticalAlignment;
                fontVerticalAlignment = format.verticalAlignment();
                verticalAlignmentChanged = true;
            }

            // detect font family change:
            if (!format.fontFamily().isEmpty() && format.fontFamily()!=fontFamily) {
                fontFamily = format.fontFamily();
                fontChanged = true;
            }

            // detect color change:
            QColor qFormatColor = format.foreground().color();
            RColor formatColor;
            if (qFormatColor==RColor::CompatByLayer) {
                formatColor = RColor(RColor::ByLayer);
            }
            else if (qFormatColor==RColor::CompatByBlock) {
                formatColor = RColor(RColor::ByBlock);
            }
            else {
                formatColor = RColor(qFormatColor);
            }
            //qDebug() << "format color: " << formatColor;
            if (formatColor!=fontColor) {
                fontColor = formatColor;
                colorChanged = true;

                //qDebug() << "color: " << fontColor;
            }


            // detect height change:
            if (format.fontPointSize() > RS::PointTolerance &&
                    fabs(format.fontPointSize()/fontHeightFactor - fontHeight) > RS::PointTolerance) {

                fontHeight = format.fontPointSize() / fontHeightFactor;
                heightChanged = true;

                //qDebug() << "height: " << format.fontPointSize();
            }

            // handle stacked text:
            QString text;
            if (verticalAlignmentChanged) {
                if (previousVerticalAlignment==QTextCharFormat::AlignNormal) {
                    ret += "\\S";
                    if (fontVerticalAlignment==QTextCharFormat::AlignSubScript) {
                        ret += "^";
                    }
                }
                else if (previousVerticalAlignment==QTextCharFormat::AlignSuperScript) {
                    ret += "^";
                    if (fontVerticalAlignment==QTextCharFormat::AlignNormal) {
                        ret += ";";
                    }
                }
                else if (previousVerticalAlignment==QTextCharFormat::AlignSubScript) {
                    ret += ";";
                    if (fontVerticalAlignment==QTextCharFormat::AlignSuperScript) {
                        ret += "\\S";
                    }
                }
            }

            if (fontChanged) {
                if (RFontList::isCadFont(fontFamily)) {
                    ret += QString("\\F%1|c0;")
                            .arg(fontFamily);
                }
                else {
                    ret += QString("\\f%1|b%2|i%3|c0|p0;")
                            .arg(fontFamily)
                            .arg(fontWeight>QFont::Normal ? 1 : 0)
                            .arg(fontItalic ? 1 : 0);
                }
            }

            if (colorChanged) {
                int colorIndex = fontColor.getColorIndex();
                if (colorIndex!=-1) {
                    ret += QString("\\C%1;").arg(colorIndex);
                }
                else {
                    ret += QString("\\c%1;").arg(fontColor.getCustomColorCode());
                }
            }

            if (heightChanged) {
                ret += QString("\\H%1;").arg(fontHeight);
            }

            text = fragment.text();

            //qDebug() << "text fragment: " << text;
//            qDebug() << "  weight: " << format.fontWeight();
//            qDebug() << "  family: " << format.fontFamily();
//            qDebug() << "  italic: " << format.fontItalic();
//            qDebug() << "  color: " << format.foreground();

            // backslash:
            text.replace("\\", "\\\\");
            // replace line separator (shift-enter):
            text.replace(QChar(0x2028), "\\p");
            // curly brakets:
            text.replace('{', "\\{");
            text.replace('}', "\\}");
            // spaces:
            text.replace(' ', "\\~");
            // degree:
            text.replace(RTextRenderer::chDegree, RTextRenderer::escDegree);
            // plus minus:
            text.replace(RTextRenderer::chPlusMinus, RTextRenderer::escPlusMinus);
            // diameter:
            text.replace(RTextRenderer::chDiameter, RTextRenderer::escDiameter);
            ret += text;
        }
    }

    if (fontVerticalAlignment==QTextCharFormat::AlignSuperScript) {
        ret += "^;";
    }
    else if (fontVerticalAlignment==QTextCharFormat::AlignSubScript) {
        ret += ";";
    }

    return ret;
}

/**
 * \return HTML representing this text.
 */
QString RTextData::toRichText(const QString& escapedText, const QFont& mainFont, double fontHeightFactor) {
    //QString str = escapedText;
    //replaceLineFeeds(str);
    //replaceNonBreakingSpaces(str);
    //replaceFonts(str);
    //replaceColorChanges(str);
    //replaceHeightChanges(str, mainFont.pointSizeF(), fontHeightFactor);
    //replaceStackedText(str);

    RTextData textData;
    textData.setFontName(mainFont.family());
    textData.setBold(mainFont.weight()>QFont::Normal);
    textData.setItalic(mainFont.italic());
    textData.setTextHeight(mainFont.pointSizeF());
    textData.setText(Qt::escape(escapedText).replace(' ', "&nbsp;"));
    RTextRenderer renderer(textData, false, RTextRenderer::RichText, fontHeightFactor);

    QString ret;

    QString fontFamily = mainFont.family();

    // workaround for QTextEdit which replaces 'bold' with '12' in all font names:
    fontFamily = fontFamily.replace("bold", "bol&#64;", Qt::CaseInsensitive);

    ret += "<html>";
    ret += QString("<body style=\"font-family:%1; font-size:%2pt; font-weight:%3; font-style:%4; \">")
            .arg(fontFamily)
            .arg(mainFont.pointSizeF() * fontHeightFactor)
            .arg(mainFont.weight()>QFont::Normal ? "bold" : "normal")
            .arg(mainFont.italic() ? "italic" : "normal");
    ret += renderer.getRichText();
    ret += "</body>";
    ret += "</html>";

    return ret;
}

/**
 * \internal HTML helper function.
 */
//void RTextData::replaceLineFeeds(QString& str) {
//    str.replace(QRegExp(RTextRenderer::rxLineFeed), "<br/>");

//    // paragraphs:
//    QString oldStr = str;
//    str.replace(QRegExp(RTextRenderer::rxParagraphFeed), "</p><p>");
//    if (str!=oldStr) {
//        str = "<p>" + str + "</p>";
//    }
//}

/**
 * \internal HTML helper function.
 */
//void RTextData::replaceNonBreakingSpaces(QString& str) {
//    str.replace(QRegExp(RTextRenderer::rxNonBreakingSpace), "&nbsp;");
//}

/**
 * \internal HTML helper function.
 */
//void RTextData::replaceFonts(QString& str) {
//    QRegExp re(RTextRenderer::rxFontChangeTtf);
//    int pos = 0;
//    int found = 0;
//    while ((pos = re.indexIn(str, 0)) != -1) {
//        QString style;
//        style += QString("font-family:%1;").arg(re.cap(1));
//        style += QString("font-weight:%1;").arg(re.cap(2)!="0" ? "bold" : "normal");
//        style += QString("font-style:%1;").arg(re.cap(3)!="0" ? "italic" : "normal");

//        str.replace(pos, re.matchedLength(), QString("<span style='%1'>").arg(style));
//        found++;
//    }

//    for (int i=0; i<found; ++i) {
//        str += "</span>";
//    }
//}

/**
 * \internal HTML helper function.
 */
// {\fArial|b0|i0|c0|p34;ABC\P\C5;abc\P\C3;123}
//void RTextData::replaceColorChanges(QString& str) {
//    QRegExp re(RTextRenderer::rxColorChangeIndex);
//    int pos = 0;
//    int found = 0;
//    while ((pos = re.indexIn(str, 0)) != -1) {
//        QString style = QString("color:%1;").arg(cadToHtmlColorIndex(re.cap(1)));
//        str.replace(pos, re.matchedLength(), QString("<span style='%1'>").arg(style));
//        found++;
//    }

//    for (int i=0; i<found; ++i) {
//        str += "</span>";
//    }

//    re.setPattern(RTextRenderer::rxColorChangeCustom);
//    pos = 0;
//    found = 0;
//    while ((pos = re.indexIn(str, 0)) != -1) {
//        QString style = QString("color:%1;").arg(cadToHtmlColorCustom(re.cap(1)));
//        str.replace(pos, re.matchedLength(), QString("<span style='%1'>").arg(style));
//        found++;
//    }

//    for (int i=0; i<found; ++i) {
//        str += "</span>";
//    }
//}

/**
 * \internal HTML helper function.
 */
// {\fArial|b1|i1|c0|p1;ABC\P\C5;\H0.666667x;abc\P\C3;\H2x;123}
//void RTextData::replaceHeightChanges(QString& str, double initialHeight, double fontHeightFactor) {
//    QRegExp re(RTextRenderer::rxHeightChange);
//    int pos = 0;

//    double height = initialHeight;

//    int found = 0;
//    while ((pos = re.indexIn(str, 0)) != -1) {
//        bool factor = re.cap(2)=="x";
//        double newHeight = re.cap(1).toDouble();
//        if (factor) {
//            height *= newHeight;
//        }
//        else {
//            height = newHeight;
//        }
//        QString style = QString("font-size:%1pt;").arg(height * fontHeightFactor);
//        str.replace(pos, re.matchedLength(), QString("<span style='%1'>").arg(style));
//        found++;
//    }

//    for (int i=0; i<found; ++i) {
//        str += "</span>";
//    }
//}

/**
 * \internal HTML helper function.
 */
//void RTextData::replaceStackedText(QString& str) {
//    QRegExp re(RTextRenderer::rxStackedText);
//    int pos = 0;

//    while ((pos = re.indexIn(str, 0)) != -1) {
//        QString super = re.cap(1);
//        QString sub = re.cap(2);
//        QString replacement = "";
//        if (!super.isEmpty()) {
//            replacement += QString("<span style='vertical-align:super;'>%1</span>").arg(super);
//        }
//        if (!sub.isEmpty()) {
//            replacement += QString("<span style='vertical-align:sub;'>%1</span>").arg(sub);
//        }
//        str.replace(pos, re.matchedLength(), replacement);
//    }
//}

/**
 * \internal HTML helper function.
 */
//QString RTextData::cadToHtmlColorIndex(const QString& str) {
//    return RColor::createFromCadIndex(str).name();
//}

/**
 * \internal HTML helper function.
 */
//QString RTextData::cadToHtmlColorCustom(const QString& str) {
//    return RColor::createFromCadCustom(str).name();
//}

QDebug operator<<(QDebug dbg, const RTextData& t) {
    dbg.nospace() << "RTextData("
                  << "text: " << t.text
                  << ", position: " << t.position
                  << ", alignmnet point: " << t.alignmentPoint
                  << ", angle: " << RMath::rad2deg(t.angle)
                  << ", pps: " << t.getPainterPaths()
                  << ")";
    return dbg;
}
