// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMACOLORCOMBO_H
        #define RECMACOLORCOMBO_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RColorCombo.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class QCADECMAAPI_EXPORT REcmaColorCombo {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getQComboBox(QScriptContext *context,
            QScriptEngine *engine)
        ;

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;

    // properties:
    

    // public methods:
    static  QScriptValue
        getColor
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setColor
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        init
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getOnlyFixed
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setOnlyFixed
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getShowAlphaChannel
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setShowAlphaChannel
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        colorChanged
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RColorCombo* getSelf(const QString& fName, QScriptContext* context)
    ;static RColorCombo* getSelfShell(const QString& fName, QScriptContext* context)
    ;static  void fromScriptValue(const QScriptValue& value,
        RColorCombo*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RColorCombo*>(o);
        }
    static  QScriptValue toScriptValue(QScriptEngine *engine,
        RColorCombo*
        const &in){
            QScriptValue s = engine->newQObject(in, QScriptEngine::QtOwnership,
            QScriptEngine::PreferExistingWrapperObject);
            /*
            if(s.isNull()){
               REcmaHelper::throwError("This object is null.", engine->currentContext());
            }
            */
            return s;
        }
    };
    #endif
    