// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #ifndef RECMANAVIGATIONACTION_H
        #define RECMANAVIGATIONACTION_H

        #include "ecmaapi_global.h"

        #include <QScriptEngine>
        #include <QScriptValue>
        #include <QScriptContextInfo>
        #include <QDebug>

        
                #include "RNavigationAction.h"
            

        /**
         * \ingroup scripting_ecmaapi
         */
        class QCADECMAAPI_EXPORT REcmaNavigationAction {

        public:
      static  void init(QScriptEngine& engine, QScriptValue* proto 
    =NULL
    ) 
    ;static  QScriptValue create(QScriptContext* context, QScriptEngine* engine) 
    ;

    // conversion functions for base classes:
    static  QScriptValue getRActionAdapter(QScriptContext *context,
            QScriptEngine *engine)
        ;static  QScriptValue getRAction(QScriptContext *context,
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
        mousePressEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mouseReleaseEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue
        mouseMoveEvent
        (QScriptContext* context, QScriptEngine* engine) 
        ;static  QScriptValue toString
    (QScriptContext *context, QScriptEngine *engine)
    ;static  QScriptValue destroy(QScriptContext *context, QScriptEngine *engine)
    ;static RNavigationAction* getSelf(const QString& fName, QScriptContext* context)
    ;static RNavigationAction* getSelfShell(const QString& fName, QScriptContext* context)
    ;};
    #endif
    