// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaSelectionListener.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RDocumentInterface.h"
            
            
        // includes for base ecma wrapper classes
         void REcmaSelectionListener::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RSelectionListener*) 0)));
        protoCreated = true;
    }

    

    QScriptValue fun;

    // toString:
    REcmaHelper::registerFunction(&engine, proto, toString, "toString");
    

    // destroy:
    REcmaHelper::registerFunction(&engine, proto, destroy, "destroy");
    

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
            REcmaHelper::registerFunction(&engine, proto, updateSelectionListener, "updateSelectionListener");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RSelectionListener*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RSelectionListener",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaSelectionListener::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RSelectionListener: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
    

    // returns class name:
     QScriptValue REcmaSelectionListener::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RSelectionListener"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaSelectionListener::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaSelectionListener::updateSelectionListener
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaSelectionListener::updateSelectionListener", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaSelectionListener::updateSelectionListener";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RSelectionListener* self = 
                        getSelf("updateSelectionListener", context);
                  

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
                        return REcmaHelper::throwError("RSelectionListener: Argument 0 is not of type RDocumentInterface *RDocumentInterface *.", context);                    
                    }
                
    // end of arguments

    // call C++ function:
    // return type 'void'
    
               self->updateSelectionListener(a0);
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RSelectionListener.updateSelectionListener().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaSelectionListener::updateSelectionListener", context, engine);
            return result;
        }
         QScriptValue REcmaSelectionListener::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RSelectionListener* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RSelectionListener(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaSelectionListener::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RSelectionListener* self = getSelf("RSelectionListener", context);
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
    RSelectionListener* REcmaSelectionListener::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RSelectionListener* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RSelectionListener >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RSelectionListener.%1(): "
                        "This object is not a RSelectionListener").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RSelectionListener* REcmaSelectionListener::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RSelectionListener* selfBase = getSelf(fName, context);
                RSelectionListener* self = dynamic_cast<RSelectionListener*>(selfBase);
                //return REcmaHelper::scriptValueTo<RSelectionListener >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RSelectionListener.%1(): "
                    "This object is not a RSelectionListener").arg(fName),
                    context);
            }

            return self;
            


        }
        