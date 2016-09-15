#include "../include/abstractcontext.h"
#include <cassert>
#include <stdexcept>

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
    if (clean_heap)
    {
        this->clean();
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
