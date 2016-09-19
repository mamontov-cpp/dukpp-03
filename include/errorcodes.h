/*! \file errorcodes.h
    

    Defines error codes wrapper for Duktape
 */
#pragma once
#include "duk_custom.h"
#include "../duktape/src/duktape.h"

namespace dukpp03
{

/*! An wrapper for error codes of Duktape 
 */
enum ErrorCodes
{
    D03_UNIMPLEMENTED_ERROR = DUK_ERR_UNIMPLEMENTED_ERROR, //!< Unimplemened error
    D03_DUK_UNSUPPORTED_ERROR = DUK_ERR_UNSUPPORTED_ERROR,     //!< Unsupported error
    D03_DUK_INTERNAL_ERROR = DUK_ERR_INTERNAL_ERROR,           //!< Internal Error
    D03_DUK_ALLOC_ERROR = DUK_ERR_ALLOC_ERROR,				   //!< AllocError 
    D03_DUK_ASSERTION_ERROR = DUK_ERR_ASSERTION_ERROR,         //!< AssertionError 
    D03_DUK_API_ERROR = DUK_ERR_API_ERROR,					   //!< APIError
    D03_DUK_UNCAUGHT_ERROR = DUK_ERR_UNCAUGHT_ERROR,           //!< UncaughtError 

    D03_DUK_E5_ERROR = DUK_ERR_ERROR,                     //!< JS E5 Error 
    D03_DUK_E5_EVAL_ERROR = DUK_ERR_EVAL_ERROR,           //!< JS E5 EvalError 
    D03_DUK_E5_RANGE_ERROR = DUK_ERR_RANGE_ERROR,		  //!< JS E5 RangeError 
    D03_DUK_E5_REFERENCE_ERROR = DUK_ERR_REFERENCE_ERROR, //!< JS E5 ReferenceError
    D03_DUK_E5_SYNTAX_ERRROR = DUK_ERR_SYNTAX_ERROR,      //!< JS E5 SyntaxError 
    D03_DUK_E5_TYPE_ERROR = DUK_ERR_TYPE_ERROR,            //!< JS E5 TypeError 
    D03_DUK_E5_URI_ERROR = DUK_ERR_URI_ERROR               //!< JS E5 URIError 
};

}
