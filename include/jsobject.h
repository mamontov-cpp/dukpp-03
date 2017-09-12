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

    /*! Releases existing resources, destroying object
     */
    virtual ~JSObject()
    {
        
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
        duk_push_object(c);
        void* heapptr = duk_get_heapptr(c, -1);
        Link lnk;
        lnk.Context = ctx;
        lnk.HeapPointer = heapptr;
        ctx->insertLinkedPointer(heapptr);
        (const_cast<JSObject<_Context>*>(this))->m_links.push_back(lnk);

        // Set inner value, stored to ensure consistency
        duk_push_string(c, DUKPP03_JSOBJECT_POINTER_SIGNATURE);   
        duk_push_pointer(c, (const_cast<JSObject<_Context>*>(this)));
        duk_def_prop(c, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);

        // Set finalizer
        duk_push_c_function(c,  dukpp03::JSObjectFinalizer<_Context>::finalize, 2);
        duk_set_finalizer(c, -1);
        printf("Set finalizer for: %p\n", duk_get_heapptr(c, -1));

        // TODO: Register fields
    }

    /*! Registers object as global in some context
        \param[in] ctx context
        \param[in] name a name of object as field
     */
    void registerAsGlobalVariable(_Context* ctx, const std::string& name)
    {
        // TODO: Actually implement registering
    }

    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
        \param[in] own whether we own it
     */
    void setProperty(const std::string& name, dukpp03::Callable<_Context>* val, bool own = true)
    {
        // TODO: 
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
     */
    void setProperty(const std::string& name, dukpp03::JSObject<_Context>* val)
    {
        // TODO: 
    }

    /*! Set null property for object
        \param[in] name a name of property
     */ 
    void setNullProperty(const std::string& name)
    {
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
        // TODO: 
    }
    /*! Sets new property of object or replaces old. Edit runtime object if needed
         \param[in] name a name of property
         \param[in] function a function
         \param[in] nargs amount of arguments in a function
     */
    void setProperty(const std::string& name, duk_c_function function, duk_idx_t nargs)
    {

        // TODO:         
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[on] val a value, that will be evaluated in context
     */
    void setEvaluatedProperty(const std::string& name, const std::string val)
    {

        // TODO: 
    }
    /*! Removes property from object
        \param[in] name a name for property of object
     */
    void deleteProperty(const std::string& name)
    {
        for(size_t i = 0; i < m_links.size(); i++)
        {
            duk_context* c = m_links[i].Context->context();
            duk_push_heapptr(c, m_links[i].HeapPointer);
            duk_del_prop_string(c, -1, name.c_str());
            duk_pop(c);
        }
        // TODO: Field-dependent removal
        // TODO: Remove field from arrays
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
        // TODO: 
        printf("Erased %p  from %p\n", heapptr, ctx);
        ctx->removeLinkedPointer(heapptr);
    }
protected:
    /*! A contexts with name where object is registered
     */
    std::vector<typename dukpp03::JSObject<_Context>::Link> m_links;
    /*! A list of parent objects
     */
    std::vector<dukpp03::JSObject<_Context>* > m_parent_objects;
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
        printf("Attempt to get pointer\n");
        dukpp03::JSObject<_Context>* result = NULL;
        duk_get_prop_string(ctx, 0, DUKPP03_JSOBJECT_POINTER_SIGNATURE);
        if (duk_is_pointer(ctx, -1))
        {
            printf("Fetching pointer\n");
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
    printf("Finalizer is called for %p: %s\n", duk_get_heapptr(ctx, 0), duk_to_string(ctx, 0));   
    duk_enum(ctx, 0, DUK_ENUM_INCLUDE_HIDDEN);
    while (duk_next(ctx, -1, 1)) {
        printf("key=%s, value=%s\n", duk_to_string(ctx, -2), duk_to_string(ctx, -1));
        duk_pop_2(ctx);
    }
    duk_pop(ctx);
    typename dukpp03::JSObject<_Context>* o = JSObjectFinalizer<_Context>::getObject(ctx);
    _Context* parent  = static_cast<_Context*>(dukpp03::AbstractContext::getContext(ctx));
    if (o) 
    {
        printf("Found object %p\n");
        void* heapptr = duk_get_heapptr(ctx, -1);
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