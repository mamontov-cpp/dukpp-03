/*! \file compiledfunction.h

    Contains definition of compiled function, that can be used to pass callbacks into other parts of code
 */
#pragma once
#include "duk_custom.h"
#include "../duktape/src/duktape.h"
#include "callable.h"
#include "getvalue.h"
#include "pushvalue.h"
#include <cstring>

namespace dukpp03
{

/*! A compiled function, that can be used to pass callbacks to other parts of code
 */
template<
   typename _Context
>
class CompiledFunction: public dukpp03::Callable<_Context>
{
public:
    /*! Constructs invalid function
     */
    CompiledFunction() : m_buffer(NULL), m_size(0)
    {
        
    }
    /*! Constructs function from specified buffer
        \param[in] buffer a buffer
        \param[in] size a size
     */
    CompiledFunction(void* buffer, size_t size) : m_size(size)
    {
        m_buffer = new char[size];
        memcpy(m_buffer, buffer, size);
    }
    /*! Copies other function
        \param[in] f function
     */
    CompiledFunction(const dukpp03::CompiledFunction<_Context>& f)
    {
        this->copy(f);
    }
    /*! Copies new function
        \param[in] f function
        \return self-reference
     */
    dukpp03::CompiledFunction<_Context>& operator=(const dukpp03::CompiledFunction<_Context>& f)
    {
        this->destroy();
        this->copy(f);
        return *this;
    }
    
    /*! Must return copy of callable object
        \return copy of callable object
     */
    virtual Callable<_Context>* clone()
    {
        return new dukpp03::CompiledFunction<_Context>(*this);
    }
    /*! Pushes current function on stack if can and deserializes it, otherwise pushes undefined
        \param[in] ctx context
     */
    void pushMeOnStack(_Context* ctx)
    {
        duk_context* c = ctx->context();
        if (valid())
        {
            void* p = duk_push_fixed_buffer(c, m_size);
            memcpy(p, m_buffer, m_size);
            duk_load_function(c);
        }
        else
        {
            duk_push_undefined(c);
        }
    }
    /*! We don't know how much arguments do we need, so return -1
        \return -1
     */
    virtual int requiredArguments()
    {
        return 0;
    }
    /*! If not valid, returns (-1, false), indicating that this function should not be called. Otherwise
        returns smallest valid value - (0, true) as we cannot check native function validity
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(_Context* c)
    {
        if (!valid())
        {
            return std::make_pair(-1, false);
        }
        return std::make_pair(0, true);
    }
    /*! Performs call on object, using specified context
        \param[in] ctx context
        \return count of values on stack, placed by functions
     */
    virtual int call(_Context* ctx)
    {
        if (!valid())
        {
            return 0;
        }
        int top = ctx->getTop();
        duk_context* c = ctx->context();
        void* p = duk_push_fixed_buffer(c, m_size);
        memcpy(p, m_buffer, m_size);
        duk_load_function(c);
        // Perform stack call 
        for(int i = 0; i < top; i++)
        {
            duk_dup(c, i);
        }
        if (duk_pcall(c, top) == DUK_EXEC_ERROR)
        {
            return DUK_RET_TYPE_ERROR;
        }
        // Also, function could return error, so check it here
        if (duk_is_error(c, -1))
        {
            return DUK_RET_TYPE_ERROR;
        }
        if (!duk_is_undefined(c, -1))
        {
            return 1;
        }
        duk_pop(c);        
        return 0;
    }
    /*! Destructs inner buffer for function
     */
    ~CompiledFunction()
    {
        this->destroy();
    }
    /*! Returns true if function buffer is set
        \return buffer
     */
    bool valid() const 
    {
        return m_buffer != NULL;
    }
protected:
    /*! Copies function state from other function
        \param[in] f buffer
     */
    void copy(const dukpp03::CompiledFunction<_Context>& f)
    {
        if (f.m_buffer)
        {
            m_size = f.m_size;
            m_buffer = new char[m_size];
            memcpy(m_buffer, f.m_buffer, m_size);
        }
        else
        {
            m_buffer = NULL;
            m_size = 0;
        }
    }
    /*! Destructs buffer value
     */
    void destroy()
    {
        delete[] reinterpret_cast<char*>(m_buffer);
    }
    /*! A buffer pointer
     */
    void* m_buffer;
    /*! A size of buffer
     */
    duk_size_t m_size;
};


template<    
    typename _Context
>
class GetValue<dukpp03::CompiledFunction<_Context>, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<dukpp03::CompiledFunction<_Context> > perform(_Context* ctx, duk_idx_t pos)
{
    dukpp03::Maybe<dukpp03::CompiledFunction<_Context> > result;
    duk_context* c = ctx->context();
    if (duk_is_ecmascript_function(c, pos))
    {
        duk_size_t  size = 0;
        duk_dup(c, pos);
        duk_dump_function(c);
        void* buffer = duk_get_buffer(c, -1, &size);
        result.setValue(dukpp03::CompiledFunction<_Context>(buffer, size));
        duk_pop(c);
    }
    return result;
}

};

template<
    typename _Context
>
class PushValue<dukpp03::CompiledFunction<_Context>, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const dukpp03::CompiledFunction<_Context>& v)
    {
        v.pushMeOnStack(ctx);
    }
};

}