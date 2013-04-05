// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaFocusListenerAdapter.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocumentInterface.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaFocusListener.h"
                 void REcmaFocusListenerAdapter::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RFocusListenerAdapter*) 0)));
        protoCreated = true;
    }

    
        // primary base class RFocusListener:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RFocusListener*>());

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
    
        // conversion for base class RFocusListener
        REcmaHelper::registerFunction(&engine, proto, getRFocusListener, "getRFocusListener");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, updateFocus, "updateFocus");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RFocusListenerAdapter*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RFocusListenerAdapter",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaFocusListenerAdapter::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RFocusListenerAdapter(): Did you forget to construct with 'new'?"),
           context);
    }

    QScriptValue result;
    
            // constructor without variants:
            
    if( context->argumentCount() ==
        0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            REcmaShellFocusListenerAdapter
                    * cppResult =
                    new
                    REcmaShellFocusListenerAdapter
                    ();
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
        cppResult->__qtscript_self = result;
    
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RFocusListenerAdapter(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaFocusListenerAdapter::getRFocusListener(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RFocusListener* cppResult =
                    qscriptvalue_cast<RFocusListenerAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaFocusListenerAdapter::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RFocusListenerAdapter"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaFocusListenerAdapter::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RFocusListener");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaFocusListenerAdapter::updateFocus
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaFocusListenerAdapter::updateFocus", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaFocusListenerAdapter::updateFocus";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RFocusListenerAdapter* self = 
                        getSelf("updateFocus", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isVariant() || 
            context->argument(0).isQObject() || 
            context->argument(0).isNull()
        ) /* type: RDocumentInterface * */
    
    ){
    // prepare arguments:
    
                    // argument is pointer
                    RDocumentInterface * a0 = NULL;

                    a0 = 
                        REcmaHelper::scriptValueTo<RDocumentInterface >(
                            context->argument(0)
                        );
                    
                    if (a0==NULL && 
                        !context->argument(0).isNull()) {
                        return REcmaHelper::throwError("RFocusListenerAdapter: Argument 0 is not of type RDocumentInterface *RDocumentInterface *.", context);                    
                    }
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->updateFocus(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RFocusListenerAdapter.updateFocus().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaFocusListenerAdapter::updateFocus", context, engine);
            return result;
        }
         QScriptValue REcmaFocusListenerAdapter::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RFocusListenerAdapter* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RFocusListenerAdapter(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaFocusListenerAdapter::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RFocusListenerAdapter* self = getSelf("RFocusListenerAdapter", context);
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
    RFocusListenerAdapter* REcmaFocusListenerAdapter::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RFocusListenerAdapter* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RFocusListenerAdapter >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RFocusListenerAdapter.%1(): "
                        "This object is not a RFocusListenerAdapter").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        REcmaShellFocusListenerAdapter* REcmaFocusListenerAdapter::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RFocusListenerAdapter* selfBase = getSelf(fName, context);
                REcmaShellFocusListenerAdapter* self = dynamic_cast<REcmaShellFocusListenerAdapter*>(selfBase);
                //return REcmaHelper::scriptValueTo<REcmaShellFocusListenerAdapter >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RFocusListenerAdapter.%1(): "
                    "This object is not a RFocusListenerAdapter").arg(fName),
                    context);
            }

            return self;
            


        }
        