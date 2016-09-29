/*! \file decay.h
    
    
    Simple decay replacement for old compilers
 */
#pragma once
#include "isnotpodreference.h"

namespace dukpp03
{

template<
    typename T
>
struct Decay
{
    typedef T Type;
};


template<
    typename T
>
struct Decay<T&>
{
    typedef T Type;
};

template<
    typename T
>
struct Decay<const T&>
{
    typedef T Type;
};

}
