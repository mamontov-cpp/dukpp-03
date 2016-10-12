/*! \file abstractcontext.h
    
    Defines an abstract context, which could be used for evaluation
 */
#pragma once
#include "errorcodes.h"
#include <string>

namespace dukpp03
{

class AbstractCallable;

/*! A wapper for basic context for data
 */
class AbstractContext
{
public:
    /*! Constructs new basic context
     */
    AbstractContext();
    /*! Can be inherited
     */
    virtual ~AbstractContext();
    /*! Tries to get current context from raw context 
        \param[in] ctx context
        \return context
     */
    static dukpp03::AbstractContext* getContext(duk_context* ctx);
    /*! Evals string, with code in it. If no error occured, result is not popped
        out from stack, since we still may need it
        \param[in] string a string
        \param[in] clean_heap whether heap should be cleaned after execution. If provided, result is popped from stack
        \param[out] error a string, where error should be written
        \return true if no error
     */
    bool eval(const std::string& string, bool clean_heap = true,std::string* error = NULL);
    /*! Throws error from a context
        \param[in] error_string string data for error
        \param[in] code error codes
     */
    void throwError(const std::string& error_string, dukpp03::ErrorCodes code = dukpp03::D03_DUK_E5_ERROR);
    /*! Resets context fully, erasing all data
     */
    virtual void reset() = 0;
    /*! Tries to perform call on specified value, passed by Duktape
        \param[in] value a value
        \return result of call
     */
    virtual int call(void* value) = 0;
    /*! Returns new context
        \return context data
     */
    virtual duk_context* context();
    /*! Checks, whether timeout is reached for context. Called, while
        evaluating value
     */
    bool timeoutReached() const;
    /*! Sets maximal execution time for a script
        \param[in] time maximal execution time
     */
    void setMaximumExecutionTime(double time);
    /*! Return maximal execution time for a script
        \return maximal execution time
     */
    double maximumExecutionTime() const;
    /*! A simple wrapper aroun duk_get_top for getting count of values on stack
        \return count of values on stack
     */
    int getTop() const; 
    /*! Throws error, that function has invalid amount of arguments
        \param[in] expected how many arguments did function expect
        \param[in] got how many arguments it got
     */ 
    virtual void throwInvalidArgumentCountError(int expected, int got);
    /*! Throws error, that invalid type has passed into function
        \param[in] type expected type
        \param[in] an argument number
     */
    virtual void throwInvalidTypeError(int argnumber, const std::string& type);
    /*! Throws error, that invalid type has passed into function as this
        \param[in] type expected type
        \param[in] an argument number
     */
    virtual void throwInvalidTypeForThisError(const std::string& type);
    /*! Throws error, that caught exception, when calling function
     */
    virtual void throwCaughtException();
    /*! Throws, error, that function should be called only as constructor
     */
    virtual void throwFunctionCallShouldBeACalledOnlyAsConstructor();
    /*! Throws, error, that function should not be called as constructor
     */
    virtual void throwFunctionCallShouldNotBeCalledAsConstructor();
protected:
    /*! Registers callable as property of global object
        \param[in] callable_name name of property of global object
        \param[in] callable a callable object
     */
    void registerCallable(const std::string& callable_name, dukpp03::AbstractCallable* callable);
    /*! Pushes callable to stack
        \param[in] callable a callable object
        \param[in] own whether context will own callable
     */
    void pushCallable(dukpp03::AbstractCallable* callable, bool own = true);
    /*! Inits context for evaluating
     */
    virtual void initContextBeforeAccessing();
    /*! Starts evaluating object, needed for data
     */
    virtual void startEvaluating() = 0;
    /*! Returns time, elapsed from evaluation
     */ 
    virtual double elapsedFromEvaluation() = 0;
    /*! Adds callable to needed set
        \param[in] c callable
     */
    virtual void addCallableToSet(dukpp03::AbstractCallable* c) = 0;
    /*! Inner context
     */
    duk_context* m_context;
    /*! A maximal execution time
     */
    double m_maximal_execution_time;
    /*! Whether execution is running
     */ 
    bool m_running;
private:
    /*! This object is non-copyable
        \param[in] p context
     */
    AbstractContext(const dukpp03::AbstractContext& p);
    /*! This object is non-copyable
        \param[in] p context
        \return self-reference
     */
    dukpp03::AbstractContext& operator=(const dukpp03::AbstractContext& p);
};

}
