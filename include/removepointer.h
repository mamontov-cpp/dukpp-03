/*! \file removepointer.h
    
    Contains file, that can be used to remove pointer from type
 */
#pragma once


namespace dukpp03
{
    
template<
    typename T
>
struct RemovePointer
{
    typedef T Type;
};


template<
    typename T
>
struct RemovePointer<T*>
{
    typedef T Type;
};


}
