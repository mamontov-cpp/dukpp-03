/*! \file abstractcontext.h
    
    Defines an abstract context, which could be used for evaluation
 */
#pragma once
#include "dukpp-03.h"
#include <string>

namespace dukpp03
{

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
    /*! Evals string, reading it from file
        \param[in] file_name name of file
        \param[in] clean_heap whether heap should be cleaned after execution. If provided, result is popped from stack
        \param[out] error a string, where error should be written
        \return true if no error
     */
    bool evalFromFile(
        const std::string& file_name,
        bool clean_heap = true,
        std::string* error = NULL
    );
    /*! Cleans non-persistent pool of objects, resetting it
     */
    void clean();
    /*! Resets context fully, erasing all data
     */
    void reset();
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
protected:
	/*! Starts evaluating object, needed for data
	 */
	virtual void startEvaluating() = 0;
	/*! Returns time, elapsed from evaluation
	 */ 
	virtual int elapsedFromEvaluation() = 0;
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
