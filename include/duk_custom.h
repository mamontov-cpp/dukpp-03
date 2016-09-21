/*! \file duk_custom.h

    Defines a built-in timeout checker for sandboxing Duktape
 */
#pragma once

#ifndef DUK_OPT_INTERRUPT_COUNTER
    #define DUK_OPT_INTERRUPT_COUNTER
#endif

#ifndef DUK_USE_INTERRUPT_COUNTER
    #define DUK_USE_INTERRUPT_COUNTER 1
#endif

#ifndef DUK_USE_DEBUGGER_SUPPORT
    #define DUK_USE_DEBUGGER_SUPPORT 1
#endif 

#ifndef DUK_USE_EXEC_TIMEOUT_CHECK

namespace dukpp03
{
    
/*! Checks for timeout of parent Duktape context
    \param[in] ptr pointer
    \return non-zero value if timeout is reached
 */
int ____check_timeout(void* ptr);

}

#define DUK_USE_EXEC_TIMEOUT_CHECK(udata)  (dukpp03::____check_timeout(udata))

#endif

#ifndef DUK_OPT_EXEC_TIMEOUT_CHECK

#define DUK_OPT_EXEC_TIMEOUT_CHECK(udata)  (dukpp03::____check_timeout(udata))

#endif