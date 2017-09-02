/*! \file curry1.h
     
    Defines a simple defines for creating bindings for lambdas, curried by first argument
 */
#pragma once
#include <functional>
#include <vector>
#include <iostream>
#include <utility>
#include "lambda.h"


namespace dukpp03
{

/*! A placeholder replacement for currying
 */
template<int N>
struct lc_placeholder 
{
    /*! A conversion element
     */
    static lc_placeholder ph; 
};

/*! An element data
 */
template<int N>
lc_placeholder<N> lc_placeholder<N>::ph;

}

namespace std 
{

/*! Define our placeholders as placeholders
 */
template<int N>
struct is_placeholder<::dukpp03::lc_placeholder<N> > : std::integral_constant<int, N> 
{ 

};

}

namespace dukpp03
{

/*! Curries function by first argument
    \param[in] val first argument
    \param[in] f function
    \return result
 */
template<
    typename _ReturnType, 
    typename _FirstType, 
    typename... _Types, 
    typename _Value, 
    int... Indices
>
std::function<_ReturnType (_Types...)> curry1(_Value val, std::function<_ReturnType (_FirstType, _Types...)> f, std::integer_sequence<int, Indices...>) 
{
    return std::bind(f, val, lc_placeholder<Indices+1>::ph...);
}

/*! Curries function by first argument
    \param[in] val first argument
    \param[in] f function
    \return result
 */
template<
    typename _ReturnType, 
    typename _FirstType, 
    typename... _Types, 
    typename _Value
>
std::function<_ReturnType (_Types...)> curry1(_Value val, std::function<_ReturnType (_FirstType, _Types...)> f) 
{
    return dukpp03::curry1(val, f,  std::make_integer_sequence<int, sizeof...(_Types)>());
}

/*! Curries function by first argument
    \param[in] val first argument
    \param[in] f function
    \return result
 */
template<
    typename _ReturnType, 
    typename _FirstType, 
    typename... _Types, 
    typename _Value
>
std::function<_ReturnType (_Types...)> curry1(_Value val, _ReturnType (*f)(_FirstType, _Types...)) 
{
    std::function<_ReturnType (_FirstType,_Types...)> ff = f;
    return dukpp03::curry1(val, ff);
}

/*! Curries first argument
 */
template<
    typename _Context
>
struct curried1 
{

/*! Makes callable from function which returns nothing and receives 0 arguments
    \param[in] f function
    \return callable version
 */
template<
   typename _Value,
   typename _Fun
>
static inline dukpp03::Callable<_Context>* from(_Value val, _Fun fun)
{
    return dukpp03::make_lambda<_Context>::from(dukpp03::curry1(val, fun));
}


};

}