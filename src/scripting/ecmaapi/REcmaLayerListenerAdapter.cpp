// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaLayerListenerAdapter.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaLayerListener.h"
                 void REcmaLayerListenerAdapter::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RLayerListenerAdapter*) 0)));
        protoCreated = true;
    }

    
        // primary base class QObject:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<QObject*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        REcmaLayerListener::init(engine, proto);
          
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class QObject
        REcmaHelper::registerFunction(&engine, proto, getQObject, "getQObject");
        
        // conversion for base class RLayerListener
        REcmaHelper::registerFunction(&engine, proto, getRLayerListener, "getRLayerListener");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

        // properties of secondary base class RLayerListener:
        

        // methods of secondary base class RLayerListener:
        

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, updateLayers, "updateLayers");
            
            REcmaHelper::registerFunction(&engine, proto, clearLayers, "clearLayers");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RLayerListenerAdapter*>(), *proto);

        
                        qScriptRegisterMetaType<
                        RLayerListenerAdapter*>(
                        &engine, toScriptValue, fromScriptValue, *proto);
                    
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RLayerListenerAdapter",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaLayerListenerAdapter::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RLayerListenerAdapter(): Did you forget to construct with 'new'?"),
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
            RLayerListenerAdapter
                    * cppResult =
                    new
                    RLayerListenerAdapter
                    ();
                
                    result = engine->newQObject(context->thisObject(), cppResult);
                
    } else 

    if( context->argumentCount() ==
        1
                && (
                
                        context->argument(
                        0
                        ).isQObject()
                ) /* type: QObject * */
            
    ){
    // prepare arguments:
    
            // argument isQObject
            QObject *
            a0 =
            qobject_cast<
            QObject *>
            ( context->argument(
            0
            ).
            toQObject()
            );
        
    // end of arguments

    // call C++ constructor:
    
            // non-copyable class:
            RLayerListenerAdapter
                    * cppResult =
                    new
                    RLayerListenerAdapter
                    (
                    a0
                    );
                
                    result = engine->newQObject(context->thisObject(), cppResult);
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RLayerListenerAdapter(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaLayerListenerAdapter::getQObject(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                QObject* cppResult =
                    qscriptvalue_cast<RLayerListenerAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaLayerListenerAdapter::getRLayerListener(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RLayerListener* cppResult =
                    qscriptvalue_cast<RLayerListenerAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaLayerListenerAdapter::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RLayerListenerAdapter"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaLayerListenerAdapter::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("QObject");
    
        list.append("RLayerListener");
    

        return qScriptValueFromSequence(engine, list);
    }
    
        // properties of secondary base class RLayerListener:
        

        // methods of secondary base class RLayerListener:
        

    // properties:
    

    // public methods:
     QScriptValue
        REcmaLayerListenerAdapter::updateLayers
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLayerListenerAdapter::updateLayers", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLayerListenerAdapter::updateLayers";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLayerListenerAdapter* self = 
                        getSelf("updateLayers", context);
                  

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
                        return REcmaHelper::throwError("RLayerListenerAdapter: Argument 0 is not of type RDocumentInterface *RDocumentInterface *.", context);                    
                    }
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->updateLayers(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLayerListenerAdapter.updateLayers().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLayerListenerAdapter::updateLayers", context, engine);
            return result;
        }
         QScriptValue
        REcmaLayerListenerAdapter::clearLayers
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaLayerListenerAdapter::clearLayers", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaLayerListenerAdapter::clearLayers";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RLayerListenerAdapter* self = 
                        getSelf("clearLayers", context);
                  

                //Q_ASSERT(self!=NULL);
                if (self==NULL) {
                    return REcmaHelper::throwError("self is NULL", context);
                }
                
    
    if( context->argumentCount() ==
    0
    ){
    // prepare arguments:
    
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->clearLayers();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RLayerListenerAdapter.clearLayers().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaLayerListenerAdapter::clearLayers", context, engine);
            return result;
        }
         QScriptValue REcmaLayerListenerAdapter::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RLayerListenerAdapter* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RLayerListenerAdapter(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaLayerListenerAdapter::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RLayerListenerAdapter* self = getSelf("RLayerListenerAdapter", context);
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
    RLayerListenerAdapter* REcmaLayerListenerAdapter::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RLayerListenerAdapter* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RLayerListenerAdapter >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RLayerListenerAdapter.%1(): "
                        "This object is not a RLayerListenerAdapter").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RLayerListenerAdapter* REcmaLayerListenerAdapter::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RLayerListenerAdapter* selfBase = getSelf(fName, context);
                RLayerListenerAdapter* self = dynamic_cast<RLayerListenerAdapter*>(selfBase);
                //return REcmaHelper::scriptValueTo<RLayerListenerAdapter >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RLayerListenerAdapter.%1(): "
                    "This object is not a RLayerListenerAdapter").arg(fName),
                    context);
            }

            return self;
            


        }
         void fromScriptValue(const QScriptValue& value,
        RLayerListenerAdapter*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RLayerListenerAdapter*>(o);
        }
     QScriptValue toScriptValue(QScriptEngine *engine,
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
    