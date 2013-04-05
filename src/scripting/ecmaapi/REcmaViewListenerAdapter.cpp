// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaViewListenerAdapter.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaViewListener.h"
                 void REcmaViewListenerAdapter::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RViewListenerAdapter*) 0)));
        protoCreated = true;
    }

    
        // primary base class QObject:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<QObject*>());

            if (dpt.isValid()) {
                proto->setPrototype(dpt);
            }
          
        /*
        REcmaViewListener::init(engine, proto);
          
        */
    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    
        // conversion for base class QObject
        REcmaHelper::registerFunction(&engine, proto, getQObject, "getQObject");
        
        // conversion for base class RViewListener
        REcmaHelper::registerFunction(&engine, proto, getRViewListener, "getRViewListener");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

        // properties of secondary base class RViewListener:
        

        // methods of secondary base class RViewListener:
        

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, updateViews, "updateViews");
            
            REcmaHelper::registerFunction(&engine, proto, clearViews, "clearViews");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RViewListenerAdapter*>(), *proto);

        
                        qScriptRegisterMetaType<
                        RViewListenerAdapter*>(
                        &engine, toScriptValue, fromScriptValue, *proto);
                    
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RViewListenerAdapter",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaViewListenerAdapter::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RViewListenerAdapter(): Did you forget to construct with 'new'?"),
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
            RViewListenerAdapter
                    * cppResult =
                    new
                    RViewListenerAdapter
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
            RViewListenerAdapter
                    * cppResult =
                    new
                    RViewListenerAdapter
                    (
                    a0
                    );
                
                    result = engine->newQObject(context->thisObject(), cppResult);
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RViewListenerAdapter(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaViewListenerAdapter::getQObject(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                QObject* cppResult =
                    qscriptvalue_cast<RViewListenerAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaViewListenerAdapter::getRViewListener(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RViewListener* cppResult =
                    qscriptvalue_cast<RViewListenerAdapter*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaViewListenerAdapter::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RViewListenerAdapter"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaViewListenerAdapter::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("QObject");
    
        list.append("RViewListener");
    

        return qScriptValueFromSequence(engine, list);
    }
    
        // properties of secondary base class RViewListener:
        

        // methods of secondary base class RViewListener:
        

    // properties:
    

    // public methods:
     QScriptValue
        REcmaViewListenerAdapter::updateViews
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaViewListenerAdapter::updateViews", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaViewListenerAdapter::updateViews";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RViewListenerAdapter* self = 
                        getSelf("updateViews", context);
                  

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
                        return REcmaHelper::throwError("RViewListenerAdapter: Argument 0 is not of type RDocumentInterface *RDocumentInterface *.", context);                    
                    }
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->updateViews(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RViewListenerAdapter.updateViews().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaViewListenerAdapter::updateViews", context, engine);
            return result;
        }
         QScriptValue
        REcmaViewListenerAdapter::clearViews
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaViewListenerAdapter::clearViews", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaViewListenerAdapter::clearViews";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RViewListenerAdapter* self = 
                        getSelf("clearViews", context);
                  

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
    
               self->clearViews();
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RViewListenerAdapter.clearViews().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaViewListenerAdapter::clearViews", context, engine);
            return result;
        }
         QScriptValue REcmaViewListenerAdapter::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RViewListenerAdapter* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RViewListenerAdapter(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaViewListenerAdapter::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RViewListenerAdapter* self = getSelf("RViewListenerAdapter", context);
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
    RViewListenerAdapter* REcmaViewListenerAdapter::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RViewListenerAdapter* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RViewListenerAdapter >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RViewListenerAdapter.%1(): "
                        "This object is not a RViewListenerAdapter").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RViewListenerAdapter* REcmaViewListenerAdapter::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RViewListenerAdapter* selfBase = getSelf(fName, context);
                RViewListenerAdapter* self = dynamic_cast<RViewListenerAdapter*>(selfBase);
                //return REcmaHelper::scriptValueTo<RViewListenerAdapter >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RViewListenerAdapter.%1(): "
                    "This object is not a RViewListenerAdapter").arg(fName),
                    context);
            }

            return self;
            


        }
         void fromScriptValue(const QScriptValue& value,
        RViewListenerAdapter*
        &out) {
            QObject* o = value.toQObject();
            out = qobject_cast<
            RViewListenerAdapter*>(o);
        }
     QScriptValue toScriptValue(QScriptEngine *engine,
        RViewListenerAdapter*
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
    