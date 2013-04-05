// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMAMATHLINEEDIT_H
        #define RECMAMATHLINEEDIT_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RMathLineEdit.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class QCADECMAAPI_EXPORT REcmaMathLineEdit {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getQLineEdit(QScriptContext *context,
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
        isAngle
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setAngle
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        isInteger
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setInteger
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setValue
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getValue
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        getError
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        clearError
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        isValid
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        setToolTip
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        slotTextChanged
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        slotTextEdited
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RMathLineEdit* getSelf(const QString& fName, QScriptContext* context)
    ;static RMathLineEdit* getSelfShell(const QString& fName, QScriptContext* context)
    ;static  void fromScriptValue(const QScriptValue& value,
        RMathLineEdit*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RMathLineEdit*>(o);
        }
    static  QScriptValue toScriptValue(QScriptEngine *engine,
        RMathLineEdit*
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
    