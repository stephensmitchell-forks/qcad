// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMALAYERLISTENERADAPTER_H
        #define RECMALAYERLISTENERADAPTER_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RLayerListenerAdapter.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class QCADECMAAPI_EXPORT REcmaLayerListenerAdapter {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getQObject(QScriptContext *context,
            QScriptEngine *engine)
        ;static  QScriptValue getRLayerListener(QScriptContext *context,
            QScriptEngine *engine)
        ;

    // returns class name:
    static  QScriptValue getClassName(QScriptContext *context, QScriptEngine *engine) 
        ;

    // returns all base classes (in case of multiple inheritance):
    static  QScriptValue getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        ;
        // properties of secondary base class RLayerListener:
        

        // methods of secondary base class RLayerListener:
        

    // properties:
    

    // public methods:
    static  QScriptValue
        updateLayers
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        clearLayers
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RLayerListenerAdapter* getSelf(const QString& fName, QScriptContext* context)
    ;static RLayerListenerAdapter* getSelfShell(const QString& fName, QScriptContext* context)
    ;static  void fromScriptValue(const QScriptValue& value,
        RLayerListenerAdapter*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RLayerListenerAdapter*>(o);
        }
    static  QScriptValue toScriptValue(QScriptEngine *engine,
        RLayerListenerAdapter*
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
    