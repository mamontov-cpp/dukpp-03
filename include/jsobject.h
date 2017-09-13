#include "context.h"
#include <vector>
#include <stdexcept>
#include <cstdio>
#pragma once

#define DUKPP03_JSOBJECT_POINTER_SIGNATURE "\1dukpp03::JSObject<_Context>\1"

namespace dukpp03
{

template<typename _Context>
class JSObject;

/*! A miscellaneous class, for performing garbage collection, 
    used as finalizer in duktape. Specialize this class, to overload
    finalization for objects of specific value.
 */
template<
    typename _Context
>
struct JSObjectFinalizer
{
    /*! Returns object to be finalized
        \param[in] ctx context
        \return variant or null if nothing
     */
    static typename dukpp03::JSObject<_Context>* getObject(duk_context* ctx);
    /*! A finalization function
        \param[in] ctx context
        \return 0
     */
    static duk_ret_t finalize(duk_context *ctx);
};

template<typename _Context>
class JSObject
{
public:
    /*! An inner field for object
     */
    class Field
    {
    public:
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const = 0;
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id) = 0;
        /*! Sets name for a field
            \param[in] name a name for a field
         */
        void setName(const std::string& name)
        {
            m_name = name;
        }
        /*! Returns name of a field
            \return name of a field
         */
        const std::string& name() const
        {
            return m_name;
        }
        /*! Field can be inherited
         */
        virtual ~Field()
        {
            
        }
    protected:
        /*! A name for a field
         */
        std::string m_name;
    };
    /*! A value field, which stores a value
     */
    template<
        typename T
    >
    class ValueField: public Field
    {
    public:
        /*! Constructs new value field
            \param[in] value a value
         */
        inline ValueField(const T& value) : m_value(value)
        {
            
        }
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            return new ValueField<T>(m_value);
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            dukpp03::PushValue<T, _Context>::perform(ctx, m_value);
            duk_put_prop_string(ctx->context(), id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~ValueField()
        {
            
        }
    protected:
        T m_value;
    };
    /*! An evaluated field, that is evaluated when registered
     */
    class EvaluatedField: public Field
    {
    public:
        /*! Constructs new value field
            \param[in] value a value
         */
        inline EvaluatedField(const std::string& value) : m_value(value)
        {
            
        }
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            return new EvaluatedField(m_value);
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            duk_context* c = ctx->context();
            duk_idx_t before = duk_get_top(c);
            duk_push_string(c, m_value.c_str());
            if (duk_peval(c) != 0)
            {
                assert(false);
            }
            duk_idx_t after = duk_get_top(c);
            int diff = after - before;
            assert( diff >= 1);

            duk_put_prop_string(c, id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~EvaluatedField()
        {
            
        }
    protected:
        std::string m_value;        
    };
    /*! A callable field, that contains any kind of callable for context
     */
    class CallableField: public Field
    {
    public:
        /*! Constructs new callable field
            \param[in] value a calalble value
            \param[in] own owned field
         */
        inline CallableField(dukpp03::Callable<_Context>* value, bool own) : m_value(value)
        {
            
        }
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            return new CallableField(m_value->clone(), true);
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            duk_context* c = ctx->context();
            ctx->pushCallable(m_value->clone());

            duk_put_prop_string(c, id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~CallableField()
        {
            if (m_own)
            {
                delete m_value;
            }
        }
    protected:
        /*! An inner callable value
         */
        dukpp03::Callable<_Context>* m_value;
        /*! Whether field owns callable value
         */
        bool m_own;
    };
    /*! A null field, that contains null
     */
    class NullField: public Field
    {
    public:
        /*! Constructs new field
         */
        inline NullField()
        {
            
        }
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            return new NullField();
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            duk_context* c = ctx->context();
            duk_push_null(c);

            duk_put_prop_string(c, id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~NullField()
        {

        }
    };
    /*! A callable field, that contains mative function
     */
    class CFunctionField: public Field
    {
    public:
        /*! Constructs new field
         */
        inline CFunctionField(duk_c_function function, duk_idx_t nargs) : m_function(function), m_nargs(nargs)
        {
            
        }
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            return new CFunctionField(m_function, m_nargs);
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            duk_context* c = ctx->context();
            duk_push_c_function(c, m_function, m_nargs);

            duk_put_prop_string(c, id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~CFunctionField()
        {

        }
    protected:
        /*! An inner stored function
         */
        duk_c_function m_function;
        /*! An inner argument count for function
         */ 
        duk_idx_t m_nargs;
    };
    /*! A callable field, that contains mative function
     */
    class JSObjectField: public Field
    {
    public:
        /*! Constructs new field
         */
        inline JSObjectField(dukpp03::JSObject<_Context>* val) : m_value(val)
        {
            if (val)
            {
                val->addRef();
            }
        }
        /*! Returns value
            \return value
         */
        dukpp03::JSObject<_Context>* value() const
        {
            return m_value;
        };
        /*! Returns a copy of field
            \return a copy of field
         */
        virtual Field* clone() const
        {
            if (!m_value)
            {
                return new JSObjectField(NULL);
            }
            else
            {
                return new JSObjectField(new dukpp03::JSObject<_Context>(*m_value));
            }
        }
        /*! Registers for object of a field
            \param[in] ctx context
            \param[in] id an id for object
         */
        virtual void registerForObject(_Context* ctx, duk_idx_t id)
        {
            duk_context* c = ctx->context();
            if (m_value)
            {
                m_value->pushOnStackOfContext(ctx);
            }
            else
            {
                duk_push_null(c);
            }

            duk_put_prop_string(c, id, this->name().c_str());
        }
        /*! Could be inherited
         */
        virtual ~JSObjectField()
        {
            if (m_value)
            {
                m_value->delRef();
            }
        }
    protected:
        /*! An inner value
         */
        dukpp03::JSObject<_Context>* m_value;
    };
    /*! A link for storing link of object to context
     */
    struct Link
    {
        _Context* Context;     //!< A linked context
        void* HeapPointer;     //!< A heap pointer
    };
    /*! Makes new empty object
     */
    JSObject() : m_refcount(0)
    {
        
    }
    /*! Makes new copied object
        \param[in] o object
     */
    JSObject(const JSObject<_Context>& o)  : m_refcount(0)
    {
        m_links.clear();
        this->copy(o);
    }
    /*! Handles assignment. Only properties are copied. Object must be correctly updated
        \param[in] o object
        \return
     */
    JSObject<_Context>& operator=(const JSObject<_Context>& o)
    {
        this->destroy();
        this->copy(o);
        return *this;
    }
    /*! Releases existing resources, destroying object
     */
    virtual ~JSObject()
    {
       this->destroy();
    }

    /*! Pushes object of context
        \param[in] ctx context
     */
    void pushOnStackOfContext(_Context* ctx) const
    {
        duk_context* c = ctx->context();
        // Add reference, so if object is replacing the same value it won't be collected
        const_cast<JSObject<_Context>*>(this)->addRef();

        // Push object and store heap pointer
        duk_idx_t obj = duk_push_object(c);
        void* heapptr = duk_get_heapptr(c, obj);
        Link lnk;
        lnk.Context = ctx;
        lnk.HeapPointer = heapptr;
        ctx->insertLinkedPointer(heapptr);
        (const_cast<JSObject<_Context>*>(this))->m_links.push_back(lnk);

        // Set inner value, stored to ensure consistency
        duk_push_string(c, DUKPP03_JSOBJECT_POINTER_SIGNATURE);   
        duk_push_pointer(c, (const_cast<JSObject<_Context>*>(this)));
        duk_def_prop(c, obj, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);

        // Set finalizer
        duk_push_c_function(c,  dukpp03::JSObjectFinalizer<_Context>::finalize, 2);
        duk_set_finalizer(c, obj);
        for(size_t i = 0; i < m_fields.size(); i++)
        {
            m_fields[i]->registerForObject(ctx, obj);
        }
        for(size_t i = 0; i < m_object_fields.size(); i++)
        {
            m_object_fields[i]->registerForObject(ctx, obj);
        }
    }

    /*! Registers object as global in some context
        \param[in] ctx context
        \param[in] name a name of object as field
     */
    void registerAsGlobalVariable(_Context* ctx, const std::string& name) const
    {
        duk_context* c = ctx->context();
        std::string::size_type pos = name.find_last_of('.');
        if (pos == std::string::npos)
        {
            duk_push_global_object(c);
            duk_push_string(c, name.c_str());
        }
        else
        {
            std::string subname = name.substr(0, pos);
            std::string propname = name.substr(pos + 1);
            duk_idx_t before = duk_get_top(c);
            duk_push_string(c, subname.c_str());
            if (duk_peval(c) != 0)
            {
                assert(false);
            }
            duk_idx_t after = duk_get_top(c);
            int diff = after - before;
            assert( diff >= 1);
            duk_push_string(c, propname.c_str());
        }
        this->pushOnStackOfContext(ctx);
        duk_put_prop(c, -3);
        duk_pop(c);
    }

    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
        \param[in] own whether we own it
     */
    void setProperty(const std::string& name, dukpp03::Callable<_Context>* val, bool own = true)
    {
        this->deleteProperty(name);
        Field* f = new CallableField(val, own);
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
     */
    void setProperty(const std::string& name, dukpp03::JSObject<_Context>* val)
    {
        if (val->hasInFields(this))
        {
            throw std::logic_error("Attempt to create loop in fields");
        }
        this->deleteProperty(name);
        JSObjectField* f = new JSObjectField(val);
        f->setName(name);
        m_object_fields.push_back(f);
        registerFieldInAllContexts(f);
    }
    /*! Test if object is in fields of other object
        \param[in] val value
        \return true, if object is in fields of other object
     */
    bool hasInFields(dukpp03::JSObject<_Context>* val)
    {
        if (this == val)
        {
            return true;
        }
        for(size_t i = 0; i < m_object_fields.size(); i++)
        {
            if (m_object_fields[i]->value())
            {
                if (m_object_fields[i]->value()->hasInFields(val))
                {
                    return true;
                }
            }
        }
        return false;
    }

    /*! Set null property for object
        \param[in] name a name of property
     */ 
    void setNullProperty(const std::string& name)
    {
        this->deleteProperty(name);
        Field* f = new NullField();
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }

    /*! Set a property for object
        \param[in] name a name of property
        \param[in] f a field
     */ 
    void setProperty(const std::string& name, Field* f)
    {
        this->deleteProperty(name);
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }

    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
     */
    void setProperty(const std::string& name, dukpp03::Maybe<dukpp03::JSObject<_Context>*> val)
    {
        if (val.exists())
        {
            this->setProperty(name, val.value());
        }
        else
        {
            this->setNullProperty(name);
        }
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] value a value of property
     */
    template<
        typename _Value
    >
    void setProperty(const std::string& name, const _Value& value)
    {
        this->deleteProperty(name);
        Field* f = new ValueField<_Value>(value);
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }
    /*! Sets new property of object or replaces old. Edit runtime object if needed
         \param[in] name a name of property
         \param[in] function a function
         \param[in] nargs amount of arguments in a function
     */
    void setProperty(const std::string& name, duk_c_function function, duk_idx_t nargs)
    {
        this->deleteProperty(name);
        Field* f = new CFunctionField(function, nargs);
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[on] val a value, that will be evaluated in context
     */
    void setEvaluatedProperty(const std::string& name, const std::string val)
    {
        this->deleteProperty(name);
        Field* f = new EvaluatedField(val);
        f->setName(name);
        m_fields.push_back(f);
        registerFieldInAllContexts(f);
    }
    /*! Removes property from object
        \param[in] name a name for property of object
     */
    void deleteProperty(const std::string& name)
    {
        bool has_field = false;
        for(size_t i = 0; i < m_fields.size(); i++)
        {
            if (m_fields[i]->name() == name)
            {
                delete m_fields[i];
                m_fields.erase(m_fields.begin() + i);
                has_field = true;
                --i;
            }
        }
        for(size_t i = 0; i < m_object_fields.size(); i++)
        {
            if (m_object_fields[i]->name() == name)
            {
                delete m_object_fields[i];
                m_object_fields.erase(m_object_fields.begin() + i);
                has_field = true;
                --i;
            }
        }
        if (has_field)
        {
            for(size_t i = 0; i < m_links.size(); i++)
            {
                duk_context* c = m_links[i].Context->context();
                duk_push_heapptr(c, m_links[i].HeapPointer);
                duk_del_prop_string(c, -1, name.c_str());
                duk_pop(c);
            }
        }
    }

    /*! Adds reference to object
     */
    void addRef()
    {
        ++m_refcount;
    }

    /*! Deletes reference from object
     */
    void delRef()
    {
        --m_refcount;
        if (m_refcount <= 0)
        {
            delete this;
        }
    }

    /*! Called, when object is erased from heap of context. Note, that this could be only one of many links to object, so, 
        we should proceed carefully.
        \param[in] ctx context
        \param[in] heapptr a heap pointer from context
     */
    void eraseLinkFromContext(_Context* ctx, void* heapptr)
    {
        ctx->removeLinkedPointer(heapptr);
        for(size_t i = 0; i < m_links.size(); i++)
        {
            if ((m_links[i].Context == ctx) && (m_links[i].HeapPointer == heapptr))
            {
                m_links.erase(m_links.begin() + i);
                this->delRef();
            }
        }
    }
protected:
    /*! Copies other object's state
        \param[in] o object
     */
    void copy(const dukpp03::JSObject<_Context>& o)
    {
        m_fields.clear();
        m_object_fields.clear();
        for(size_t i = 0; i < o.m_fields.size(); i++)
        {
            m_fields.push_back(o.m_fields[i]->clone());
            registerFieldInAllContexts(o.m_fields[i]);
        }
        for(size_t i = 0; i < o.m_object_fields.size(); i++)
        {
            m_object_fields.push_back(static_cast<JSObjectField*>(o.m_object_fields[i]->clone()));
            registerFieldInAllContexts(o.m_object_fields[i]);
        }
    }
    /*! Destroys an object
     */
    void destroy()
    {
        for(size_t i = 0 ; i < m_fields.size(); i++)
        {
            delete m_fields[i];
        }
        for(size_t i = 0 ; i < m_object_fields.size(); i++)
        {
            delete m_object_fields[i];
        }
        m_fields.clear();
        m_object_fields.clear();
    }
    /*! Registers field in all contexts
     */
    void registerFieldInAllContexts(Field* f)
    {
        for(size_t i = 0; i < m_links.size(); i++)
        {
            duk_idx_t obj = duk_push_heapptr(m_links[i].Context->context(), m_links[i].HeapPointer);
            f->registerForObject(m_links[i].Context, obj);
            duk_pop(m_links[i].Context->context());
        }
    }
    /*! A contexts with name where object is registered
     */
    std::vector<typename dukpp03::JSObject<_Context>::Link> m_links;
    /*! A local field list
     */ 
    std::vector<Field*> m_fields;
    /*! An object field list
     */
    std::vector<JSObjectField*> m_object_fields;
    /*! A reference counting
     */
    unsigned int m_refcount;
};

template<
    typename _Context
>
typename dukpp03::JSObject<_Context>* JSObjectFinalizer<_Context>::getObject(duk_context* ctx)
{
    if (duk_is_object(ctx, 0))
    {
        dukpp03::JSObject<_Context>* result = NULL;
        duk_get_prop_string(ctx, 0, DUKPP03_JSOBJECT_POINTER_SIGNATURE);
        if (duk_is_pointer(ctx, -1))
        {
            void* ptr = duk_to_pointer(ctx, -1);
            result = reinterpret_cast<dukpp03::JSObject<_Context>*>(ptr);
        }
        duk_pop(ctx);
        return result;
    }
    return NULL;
}


template<
    typename _Context
>
duk_ret_t JSObjectFinalizer<_Context>::finalize(duk_context *ctx)
{
    typename dukpp03::JSObject<_Context>* o = JSObjectFinalizer<_Context>::getObject(ctx);
    _Context* parent  = static_cast<_Context*>(dukpp03::AbstractContext::getContext(ctx));
    if (o) 
    {
        void* heapptr = duk_get_heapptr(ctx, 0);
        if (parent->isLinkedPointerStored(heapptr))
        {
            o->eraseLinkFromContext(parent, heapptr);
        }
    }
    return 0;
}

/*! Makes possible to return an object from a function
 */
template<
    typename _Context
>
class PushValue<dukpp03::JSObject<_Context>*, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const dukpp03::JSObject<_Context>* v)
    {
        if (v)
        {
            v->pushOnStackOfContext(ctx);
        }
        else
        {
            duk_push_null(ctx->context());
        }
    }
};

/*! Makes possible to return an object or null from a function
 */
template<
    typename _Context
>
class PushValue<dukpp03::Maybe<dukpp03::JSObject<_Context>*>, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const dukpp03::Maybe<dukpp03::JSObject<_Context>*>& v)
    {
        if (v.exists())
        {
            dukpp03::PushValue<dukpp03::JSObject<_Context>*, _Context>::perform(ctx, v.value());
        }
        else
        {
            duk_push_null(ctx->context());
        }
    }
};

}