// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaNavigationAction.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaActionAdapter.h"
                 void REcmaNavigationAction::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RNavigationAction*) 0)));
        protoCreated = true;
    }

    
        // primary base class RActionAdapter:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RActionAdapter*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class RActionAdapter
        REcmaHelper::registerFunction(&engine, proto, getRActionAdapter, "getRActionAdapter");
        
        // conversion for base class RAction
        REcmaHelper::registerFunction(&engine, proto, getRAction, "getRAction");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, mousePressEvent, "mousePressEvent");
            
            REcmaHelper::registerFunction(&engine, proto, mouseReleaseEvent, "mouseReleaseEvent");
            
            REcmaHelper::registerFunction(&engine, proto, mouseMoveEvent, "mouseMoveEvent");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RNavigationAction*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RNavigationAction",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaNavigationAction::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RNavigationAction(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
        
            // generate constructor variants:
            
    if( context->argumentCount() ==
        0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RNavigationAction
                    * cppResult =
                    new
                    RNavigationAction
                    ();
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    if( context->argumentCount() ==
        1
                && (
                
                        context->argument(
                        0
                        ).isQObject()
                ) /* type: RGuiAction * */
            
    ){
    // prepare arguments:
    
                    // argument is pointer
                    RGuiAction * a0 = NULL;

                    a0 = 
                        REcmaHelper::scriptValueTo<RGuiAction >(
                            context->argument(0)
                        );
                    
                    if (a0==NULL && 
                        !context->argument(0).isNull()) {
                        return REcmaHelper::throwError("RNavigationAction: Argument 0 is not of type RGuiAction *RGuiAction *.", context);                    
                    }
                
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RNavigationAction
                    * cppResult =
                    new
                    RNavigationAction
                    (
                    a0
                    );
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RNavigationAction(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaNavigationAction::getRActionAdapter(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RActionAdapter* cppResult =
                    qscriptvalue_cast<RNavigationAction*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaNavigationAction::getRAction(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RAction* cppResult =
                    qscriptvalue_cast<RNavigationAction*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaNavigationAction::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RNavigationAction"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaNavigationAction::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RActionAdapter");
    
        list.append("RAction");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaNavigationAction::mousePressEvent
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaNavigationAction::mousePressEvent", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaNavigationAction::mousePressEvent";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RNavigationAction* self = 
                        getSelf("mousePressEvent", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RMouseEvent */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RMouseEvent*
                    ap0 =
                    qscriptvalue_cast<
                    RMouseEvent*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RNavigationAction: Argument 0 is not of type RMouseEvent*.",
                               context);                    
                    }
                    RMouseEvent& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->mousePressEvent(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RNavigationAction.mousePressEvent().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaNavigationAction::mousePressEvent", context, engine);
            return result;
        }
         QScriptValue
        REcmaNavigationAction::mouseReleaseEvent
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaNavigationAction::mouseReleaseEvent", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaNavigationAction::mouseReleaseEvent";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RNavigationAction* self = 
                        getSelf("mouseReleaseEvent", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RMouseEvent */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RMouseEvent*
                    ap0 =
                    qscriptvalue_cast<
                    RMouseEvent*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RNavigationAction: Argument 0 is not of type RMouseEvent*.",
                               context);                    
                    }
                    RMouseEvent& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->mouseReleaseEvent(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RNavigationAction.mouseReleaseEvent().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaNavigationAction::mouseReleaseEvent", context, engine);
            return result;
        }
         QScriptValue
        REcmaNavigationAction::mouseMoveEvent
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaNavigationAction::mouseMoveEvent", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaNavigationAction::mouseMoveEvent";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RNavigationAction* self = 
                        getSelf("mouseMoveEvent", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RMouseEvent */
    
    ){
    // prepare arguments:
    
                    // argument is reference
                    RMouseEvent*
                    ap0 =
                    qscriptvalue_cast<
                    RMouseEvent*
                        >(
                        context->argument(
                        0
                        )
                    );
                    if( ap0 == NULL ){
                           return REcmaHelper::throwError("RNavigationAction: Argument 0 is not of type RMouseEvent*.",
                               context);                    
                    }
                    RMouseEvent& a0 = *ap0;
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->mouseMoveEvent(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RNavigationAction.mouseMoveEvent().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaNavigationAction::mouseMoveEvent", context, engine);
            return result;
        }
         QScriptValue REcmaNavigationAction::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RNavigationAction* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RNavigationAction(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaNavigationAction::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RNavigationAction* self = getSelf("RNavigationAction", context);
        //Q_ASSERT(self!=NULL);
        if (self==NULL) {
            return REcmaHelper::throwError("self is NULL", context);
        }
        
    
        delete self;
        context->thisObject().setData(engine->nullValue());
        context->thisObject().prototype().setData(engine->nullValue());
        context->thisObject().setPrototype(engine->nullValue());
        context->thisObject().setScriptClass(NULL);
        return engine->undefinedValue();
    }
    RNavigationAction* REcmaNavigationAction::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RNavigationAction* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RNavigationAction >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RNavigationAction.%1(): "
                        "This object is not a RNavigationAction").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RNavigationAction* REcmaNavigationAction::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RNavigationAction* selfBase = getSelf(fName, context);
                RNavigationAction* self = dynamic_cast<RNavigationAction*>(selfBase);
                //return REcmaHelper::scriptValueTo<RNavigationAction >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RNavigationAction.%1(): "
                    "This object is not a RNavigationAction").arg(fName),
                    context);
            }

            return self;
            


        }
        