// ***** AUTOGENERATED CODE, DO NOT EDIT *****
            // ***** This class is not copyable.
        
        #include "REcmaSnapMiddle.h"
        #include "RMetaTypes.h"
        #include "../REcmaHelper.h"

        // forwards declarations mapped to includes
        
                #include "RMouseEvent.h"
            
            
        // includes for base ecma wrapper classes
        
                  #include "REcmaSnapEntityBase.h"
                 void REcmaSnapMiddle::init(QScriptEngine& engine, QScriptValue* proto 
    
    ) 
    
    {

    bool protoCreated = false;
    if(proto == NULL){
        proto = new QScriptValue(engine.newVariant(qVariantFromValue(
                (RSnapMiddle*) 0)));
        protoCreated = true;
    }

    
        // primary base class RSnapEntityBase:
        
            QScriptValue dpt = engine.defaultPrototype(
                qMetaTypeId<RSnapEntityBase*>());

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
    
        // conversion for base class RSnapEntityBase
        REcmaHelper::registerFunction(&engine, proto, getRSnapEntityBase, "getRSnapEntityBase");
        
        // conversion for base class RSnap
        REcmaHelper::registerFunction(&engine, proto, getRSnap, "getRSnap");
        

    // get class name
    REcmaHelper::registerFunction(&engine, proto, getClassName, "getClassName");
    

    // conversion to all base classes (multiple inheritance):
    REcmaHelper::registerFunction(&engine, proto, getBaseClasses, "getBaseClasses");
    

    // properties:
    

    // methods:
    
        engine.setDefaultPrototype(
            qMetaTypeId<RSnapMiddle*>(), *proto);

        
    

    QScriptValue ctor = engine.newFunction(create, *proto, 2);
    
    // static methods:
    

    // static properties:
    

    // enum values:
    

    // enum conversions:
    
        
    // init class:
    engine.globalObject().setProperty("RSnapMiddle",
    ctor, QScriptValue::SkipInEnumeration);
    
    if( protoCreated ){
       delete proto;
    }
    
    }
     QScriptValue REcmaSnapMiddle::create(QScriptContext* context, QScriptEngine* engine) 
    
    {
    if (context->thisObject().strictlyEquals(
       engine->globalObject())) {
       return REcmaHelper::throwError(
       QString::fromLatin1("RSnapMiddle(): Did you forget to construct with 'new'?"),
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
            RSnapMiddle
                    * cppResult =
                    new
                    RSnapMiddle
                    ();
                
                    // TODO: triggers: Warning: QScriptEngine::newVariant(): changing class of non-QScriptObject not supported:
                    result = engine->newVariant(context->thisObject(), qVariantFromValue(cppResult));
                
    } else 

    {
       return REcmaHelper::throwError(
       QString::fromLatin1("RSnapMiddle(): no matching constructor found."),
           context);
    }
    
    return result;
    }
    

    // conversion functions for base classes:
     QScriptValue REcmaSnapMiddle::getRSnapEntityBase(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RSnapEntityBase* cppResult =
                    qscriptvalue_cast<RSnapMiddle*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
             QScriptValue REcmaSnapMiddle::getRSnap(QScriptContext *context,
            QScriptEngine *engine)
        
            {
                RSnap* cppResult =
                    qscriptvalue_cast<RSnapMiddle*> (context->thisObject());
                QScriptValue result = qScriptValueFromValue(engine, cppResult);
                return result;
            }
            

    // returns class name:
     QScriptValue REcmaSnapMiddle::getClassName(QScriptContext *context, QScriptEngine *engine) 
        
    {
        return qScriptValueFromValue(engine, QString("RSnapMiddle"));
    }
    

    // returns all base classes (in case of multiple inheritance):
     QScriptValue REcmaSnapMiddle::getBaseClasses(QScriptContext *context, QScriptEngine *engine) 
        
    {
        QStringList list;
        
        list.append("RSnapEntityBase");
    
        list.append("RSnap");
    

        return qScriptValueFromSequence(engine, list);
    }
    

    // properties:
    

    // public methods:
     QScriptValue REcmaSnapMiddle::toString
    (QScriptContext *context, QScriptEngine *engine)
    
    {

    RSnapMiddle* self = getSelf("toString", context);
    
    QString result;
    
            result = QString("RSnapMiddle(0x%1)").arg((unsigned long int)self, 0, 16);
        
    return QScriptValue(result);
    }
     QScriptValue REcmaSnapMiddle::destroy(QScriptContext *context, QScriptEngine *engine)
    
    {

        RSnapMiddle* self = getSelf("RSnapMiddle", context);
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
    RSnapMiddle* REcmaSnapMiddle::getSelf(const QString& fName, QScriptContext* context)
    
        {
            RSnapMiddle* self = NULL;

            
                // self could be a normal object (e.g. from an UI file) or
                // an ECMA shell object (made from an ECMA script):
                //self = getSelfShell(fName, context);
                

            //if (self==NULL) {
                self = REcmaHelper::scriptValueTo<RSnapMiddle >(context->thisObject())
                
                ;
            //}

            if (self == NULL){
                // avoid recursion (toString is used by the backtrace):
                if (fName!="toString") {
                    REcmaHelper::throwError(QString("RSnapMiddle.%1(): "
                        "This object is not a RSnapMiddle").arg(fName),
                        context);
                }
                return NULL;
            }

            return self;
        }
        RSnapMiddle* REcmaSnapMiddle::getSelfShell(const QString& fName, QScriptContext* context)
    
        {
          RSnapMiddle* selfBase = getSelf(fName, context);
                RSnapMiddle* self = dynamic_cast<RSnapMiddle*>(selfBase);
                //return REcmaHelper::scriptValueTo<RSnapMiddle >(context->thisObject());
            if(self == NULL){
                REcmaHelper::throwError(QString("RSnapMiddle.%1(): "
                    "This object is not a RSnapMiddle").arg(fName),
                    context);
            }

            return self;
            


        }
        