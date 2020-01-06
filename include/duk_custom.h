/*! \file duk_custom.h

    Defines a built-in timeout checker for sandboxing Duktape
 */
#pragma once

#define DUK_USE_INTERRUPT_COUNTER
#define DUK_USE_DEBUGGER_SUPPORT
#define DUK_USE_DATE_NOW_WINDOWS 1

namespace dukpp03
{
    
/*! Checks for timeout of parent Duktape context
    \param[in] ptr pointer
    \return non-zero value if timeout is reached
 */
int ____check_timeout(void* ptr);

}

#define DUK_USE_EXEC_TIMEOUT_CHECK(udata)  (dukpp03::____check_timeout(udata))
