#include "context.h"
#include <vector>
#include <stdexcept>
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
        unsigned int RefCount; //!< A reference counter data
    };
    /*! Makes new empty object
     */
    JSObject() : m_refcount(0), m_is_null(false)
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
        
    }

    /*! Registers object as global in some context
        \param[in] ctx context
        \param[in] name a name of object as field
     */
     void registerAsGlobalVariable(_Context* ctx, const std::string& name) const
    {
        bool found = false;
        for(size_t i = 0; i < m_links.size(); i++)
        {
            if (m_links[i].Context == ctx)
            {
                found = true;
                ++m_links[i].RefCount;
            }
        }
        // TODO: Actually implement registering
    }

    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
        \param[in] own whether we own it
     */
    void setProperty(const std::string& name, dukpp03::Callable<_Context>* val, bool own = true)
    {
        this->throwPropertyCannotBeSetfNullObject();


        // TODO: 
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[in] val a value
     */
    void setProperty(const std::string& name, dukpp03::JSObject<_Context>* val)
    {
        this->throwPropertyCannotBeSetfNullObject();


        // TODO: 
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
        this->throwPropertyCannotBeSetfNullObject();


        // TODO: 
    }
    /*! Sets new property of object or replaces old. Edit runtime object if needed
         \param[in] name a name of property
         \param[in] function a function
     */
    void setProperty(const std::string& name, duk_c_function function)
    {
        this->throwPropertyCannotBeSetfNullObject();


        // TODO:         
    }
    /*! Sets new property of object or replaces old. Edits runtime object if needed. If property exists, replaces it
        \param[in] name a name of property
        \param[on] val a value, that will be evaluated in context
     */
    void setEvaluatedProperty(const std::string& name, const std::string val)
    {
        this->throwPropertyCannotBeSetfNullObject();

        // TODO: 
    }
    /*! Removes property from object
        \param[in] name a name for property of object
     */
    void deleteProperty(const std::string& name)
    {
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to remove property from a null object");
        }
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

    /*! Returns null object
     */
    static JSObject<_Context>* null()
    {
        JSObject<_Context>* result = new JSObject<_Context>();
        result->m_is_null = true;
        return result;
    }

    /*! Called, when object is erased from heap of context. Note, that this could be only one of many links to object, so, 
        we should proceed carefully.
        \param[in] ctx context
     */
    void eraseLinkFromContext(_Context* ctx)
    {
        // TODO: 
    }
protected:
    /*! Throws exception if object is null. Used to mark operations, that can be 
     */
    void throwPropertyCannotBeSetfNullObject() const
    {
        if (m_is_null)
        {
            throw new std::logic_error("Attempted to add property to a null object");
        }
    }
    /*! A contexts with name where object is registered
     */
    std::vector<typename dukpp03::JSObject<_Context>::Link> m_links;
    /*! A list of parent objects
     */
    std::vector<dukpp03::JSObject<_Context>* > m_parent_objects;
    /*! A reference counting
     */
    unsigned int m_refcount;
    /*! Whether we should push null value for object
     */
    bool m_is_null;
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
    if (o && parent->isLinkedPointerStored(o)) 
    {
        o->eraseLinkFromContext(parent);
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
        // TODO:
    }
};

}