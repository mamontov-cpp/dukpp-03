#include "../include/abstractcontext.h"
#include "../include/callable.h"
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <iostream>

/*! A property, where located pointer to callable in wrapper
 */
#define DUKPP03_NATIVE_FUNCTION_SIGNATURE_PROPERTY "\1_____native_signature\1"

dukpp03::AbstractContext::AbstractContext() : m_maximal_execution_time(30000), m_running(false)
{
    m_context = duk_create_heap(NULL,NULL, NULL, this, NULL);
}

dukpp03::AbstractContext::~AbstractContext()
{
    duk_destroy_heap(m_context);
}


dukpp03::AbstractContext* dukpp03::AbstractContext::getContext(duk_context* ctx)
{
    duk_memory_functions funcs;
    duk_get_memory_functions(ctx, &funcs);
    assert( funcs.udata );
    return static_cast<dukpp03::AbstractContext*>(funcs.udata);
}

bool dukpp03::AbstractContext::eval(const std::string& string, bool clean_heap, std::string* error)
{
    m_running = true;
    startEvaluating();
    duk_push_string(m_context, string.c_str());
    bool result = false;
    if (duk_peval(m_context) != 0) 
    {
        if (error)
        {
            *error = duk_safe_to_string(m_context, -1);
        }
        duk_pop(m_context);
    } 
    else 
    {
        if (error)
        {
            *error = "";
        }
        result = true;
        if (clean_heap)
        {
            duk_pop(m_context);
        }
    }
    m_running = false;
    return result;
}


duk_context* dukpp03::AbstractContext::context()
{
    this->initContextBeforeAccessing();
    return m_context;
}

bool dukpp03::AbstractContext::timeoutReached() const
{
    if (!m_running)
    {
        return false;
    }
    double elapsed_time = const_cast<dukpp03::AbstractContext*>(this)->elapsedFromEvaluation();
    return (elapsed_time >= m_maximal_execution_time);
}

void dukpp03::AbstractContext::setMaximumExecutionTime(double time)
{
    m_maximal_execution_time = time;
}

double dukpp03::AbstractContext::maximumExecutionTime() const
{
    return m_maximal_execution_time;
}

void dukpp03::AbstractContext::throwError(const std::string& error_string, dukpp03::ErrorCodes code)
{
    duk_push_error_object(m_context, static_cast<int>(code), error_string.c_str());
    if (m_running) 
    {
        duk_throw(m_context);
    }
}

int dukpp03::AbstractContext::getTop() const
{
    return duk_get_top(m_context);
}

void dukpp03::AbstractContext::throwInvalidArgumentCountError(int expected, int got)
{
    std::ostringstream ss;
    ss << "Function expects " << expected << " arguments, but "  <<  got << " given";
    this->throwError(ss.str());
}

void dukpp03::AbstractContext::throwInvalidTypeError(int argnumber, const std::string& type)
{
    std::ostringstream ss;
    ss << "Invalid type passed for argument #" << argnumber << ". Argument #" <<  argnumber << " must have type " << type;
    this->throwError(ss.str(), dukpp03::D03_DUK_API_ERROR);
}


void dukpp03::AbstractContext::throwInvalidTypeForThisError(const std::string& type)
{
    std::ostringstream ss;
    ss << "Invalid type passed as this. Current object must have type " << type;
    this->throwError(ss.str(), dukpp03::D03_DUK_API_ERROR);
}


void dukpp03::AbstractContext::throwFunctionCallShouldBeACalledOnlyAsConstructor()
{
    this->throwError("Function should be called only as constructor");
}

void dukpp03::AbstractContext::throwFunctionCallShouldNotBeCalledAsConstructor()
{
    this->throwError("Function should not be called as constructor");
}

void dukpp03::AbstractContext::throwCaughtException()
{
    this->throwError("Caught exception while calling function");
}

static int dukpp03_context_invoke_wrapper(duk_context *ctx) {
    duk_push_current_function(ctx);
    duk_get_prop_string(ctx, -1, DUKPP03_NATIVE_FUNCTION_SIGNATURE_PROPERTY);
    void* callableptr = duk_to_pointer(ctx, -1);
    duk_pop(ctx);
    duk_pop(ctx);

    assert(callableptr);
    dukpp03::AbstractContext* c =  dukpp03::AbstractContext::getContext(ctx);
    return c->call(callableptr);
}

void dukpp03::AbstractContext::pushCallable(dukpp03::AbstractCallable* callable)
{
   assert(callable);
   addCallableToSet(callable);
   
   duk_push_c_function(m_context, dukpp03_context_invoke_wrapper, DUK_VARARGS);
   
   duk_push_string(m_context, DUKPP03_NATIVE_FUNCTION_SIGNATURE_PROPERTY);   
   duk_push_pointer(m_context, callable);
   duk_def_prop(m_context, -3, DUK_DEFPROP_HAVE_VALUE | DUK_DEFPROP_HAVE_WRITABLE | 0);
  
}

void dukpp03::AbstractContext::registerCallable(const std::string& callable_name, dukpp03::AbstractCallable* callable)
{
   duk_push_global_object(m_context);
   
   this->pushCallable(callable);

   duk_put_prop_string(m_context, -2 /*idx:global*/, callable_name.c_str());
   duk_pop(m_context);  
}

// ================================= PROTECTED METHODS =================================

void dukpp03::AbstractContext::initContextBeforeAccessing()
{
    
}

// ================================= PRIVATE METHODS =================================

dukpp03::AbstractContext::AbstractContext(const dukpp03::AbstractContext& p)
{
    throw std::logic_error("dukpp03::AbstractContext is non-copyable!");
}

dukpp03::AbstractContext& dukpp03::AbstractContext::operator=(const dukpp03::AbstractContext& p)
{
    throw std::logic_error("dukpp03::AbstractContext is non-copyable!");
    return *this;
}

// ===================== dukpp03::____check_timeout ===========================

int dukpp03::____check_timeout(void* ptr)
{
    if (!ptr)
    {
        return 0;
    }
    if (static_cast<dukpp03::AbstractContext*>(ptr)->timeoutReached())
        return 1;
    return 0;
}
