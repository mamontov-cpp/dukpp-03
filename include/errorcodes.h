/*! \file errorcodes.h
    

    Defines error codes wrapper for Duktape
 */
#pragma once
#include "duk_custom.h"
#include "../duktape/src/duktape.h"
#include "../duktape/extras/print-alert/duk_print_alert.h"

namespace dukpp03
{

/*! An wrapper for error codes of Duktape 
 */
enum ErrorCodes
{
    D03_DUK_ERROR = DUK_ERR_ERROR,                     //!< JS Error 
    D03_DUK_EVAL_ERROR = DUK_ERR_EVAL_ERROR,           //!< JS EvalError 
    D03_DUK_RANGE_ERROR = DUK_ERR_RANGE_ERROR,         //!< JS RangeError 
    D03_DUK_REFERENCE_ERROR = DUK_ERR_REFERENCE_ERROR, //!< JS ReferenceError
    D03_DUK_SYNTAX_ERROR = DUK_ERR_SYNTAX_ERROR,      //!< JS SyntaxError 
    D03_DUK_TYPE_ERROR = DUK_ERR_TYPE_ERROR,           //!< JS TypeError 
    D03_DUK_URI_ERROR = DUK_ERR_URI_ERROR              //!< JS URIError 
};

}
