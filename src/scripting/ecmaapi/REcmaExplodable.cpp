// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaExplodable.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
            
        // includes for base ecma wrapper classes
         void REcmaExplodable::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RExplodable*) 0)));
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
    
            REcmaHelper::registerFunction(&engine, proto, getExploded, "getExploded");
            
        engine.setDefaultPrototype(
            qMetaTypeId<RExplodable*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RExplodable",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaExplodable::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
           return REcmaHelper::throwError("Abstract class RExplodable: Cannot be constructed.",
               context); 
    }
    

    // conversion functions for base classes:
    

    // returns class name:
     QScriptValue REcmaExplodable::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RExplodable"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaExplodable::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue
        REcmaExplodable::getExploded
        (QScriptContext* context, QScriptEngine* engine) 
        
        {
            //REcmaHelper::functionStart("REcmaExplodable::getExploded", context, engine);
            //qDebug() << "ECMAScript WRAPPER: REcmaExplodable::getExploded";
            //QCoreApplication::processEvents();

            QScriptValue result = engine->undefinedValue();
            
                    // public function: can be called from ECMA wrapper of ECMA shell:
                    RExplodable* self = 
                        getSelf("getExploded", context);
                  

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
    // return type 'QList < QSharedPointer < RShape > >'
    QList < QSharedPointer < RShape > > cppResult =
        
               self->getExploded();
        // return type: QList < QSharedPointer < RShape > >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
    
    if( context->argumentCount() ==
    1 && (
            context->argument(0).isNumber()
        ) /* type: int */
    
    ){
    // prepare arguments:
    
                    // argument isStandardType
                    int
                    a0 =
                    (int)
                    
                    context->argument( 0 ).
                    toNumber();
                
    // end of arguments

    // call C++ function:
    // return type 'QList < QSharedPointer < RShape > >'
    QList < QSharedPointer < RShape > > cppResult =
        
               self->getExploded(a0);
        // return type: QList < QSharedPointer < RShape > >
                // List of ...:
                result = REcmaHelper::listToScriptValue(engine, cppResult);
            
    } else


        
            {
               return REcmaHelper::throwError("Wrong number/types of arguments for RExplodable.getExploded().",
                   context);
            }
            //REcmaHelper::functionEnd("REcmaExplodable::getExploded", context, engine);
            return result;
        }
         QScriptValue REcmaExplodable::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RExplodable* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RExplodable(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaExplodable::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RExplodable* self = getSelf("RExplodable", context);
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
    RExplodable* REcmaExplodable::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RExplodable* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RExplodable >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RExplodable.%1(): "
                        "This object is not a RExplodable").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RExplodable* REcmaExplodable::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RExplodable* selfBase = getSelf(fName, context);
                RExplodable* self = dynamic_cast<RExplodable*>(selfBase);
                //return REcmaHelper::scriptValueTo<RExplodable >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RExplodable.%1(): "
                    "This object is not a RExplodable").arg(fName),
                    context);
            }

            return self;
            


        }
        