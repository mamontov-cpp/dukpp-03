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
            printf("Set property %s\n", this->name().c_str());
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
    //!< TODO: Copy constructor and assignment overload here
    /*! Releases existing resources, destroying object
     */
    virtual ~JSObject()
    {
		printf("Object is killed\n");
        for(size_t i = 0 ; i < m_fields.size(); i++)
        {
            delete m_fields[i];
        }
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
        // TODO: Register object fields
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

        // TODO: 
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
     */
    void setProperty(const std::string& name, dukpp03::JSObject<_Context>* val)
    {
        this->deleteProperty(name);

        // TODO: 
    }

    /*! Set null property for object
        \param[in] name a name of property
     */ 
    void setNullProperty(const std::string& name)
    {
        this->deleteProperty(name);
        // TODO:
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
		printf("Attempting to register property\n");
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

        // TODO:         
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
        // TODO: Same for jsobject fields
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
    /*! Registers field in all contexts
     */
    void registerFieldInAllContexts(Field* f)
    {
        for(size_t i = 0; i < m_links.size(); i++)
        {
            duk_push_heapptr(m_links[i].Context->context(), m_links[i].HeapPointer);
            f->registerForObject(m_links[i].Context, -1);
            duk_pop(m_links[i].Context->context());
        }
    }
    /*! A contexts with name where object is registered
     */
    std::vector<typename dukpp03::JSObject<_Context>::Link> m_links;
    /*! A local field list
     */ 
    std::vector<Field*> m_fields;
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