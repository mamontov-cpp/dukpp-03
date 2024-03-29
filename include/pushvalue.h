/*! \file pushvalue.h
    

    Describes an operations, that could be used to push value on a stack of Duktape
 */
#pragma once
// ReSharper disable once CppUnusedIncludeDirective
#include "context.h"
#include "maybe.h"
#include <string>

namespace dukpp03
{

/*! Performs pushing value on stack for every type of value
 */
template<
    typename _Value,
    typename _Context
>
class PushValue
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const _Value& v)
    {        
        ctx->template pushVariant<_Value>(_Context::VariantUtils::template makeFrom(v));
    }
};

template<
    typename _Context
>
class PushValue<bool, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const bool& v)
    {
        duk_push_boolean(ctx->context(), v);
    }
};


template<
    typename _Context
>
class PushValue<char, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const char& v)
    {
        char buffer[2] = {v, 0};
        duk_push_string(ctx->context(), buffer);
    }
};


template<
    typename _Context
>
class PushValue<signed char , _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const signed char& v)
    {
        dukpp03::PushValue<char, _Context>::perform(ctx, v);
    }
};

template<
    typename _Context
>
class PushValue<unsigned char, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const unsigned char& v)
    {
        char buffer[2] = {*reinterpret_cast<const char*>(&v), 0};
        duk_push_string(ctx->context(), buffer);
    }
};

template<
    typename _Context
>
class PushValue<short, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const short& v)
    {
        duk_push_int(ctx->context(), v);
    }
};

template<
    typename _Context
>
class PushValue<unsigned short, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const unsigned short& v)
    {
        duk_push_int(ctx->context(), v);
    }
};


template<
    typename _Context
>
class PushValue<int, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const int& v)
    {
        duk_push_int(ctx->context(), v);
    }
};


template<
    typename _Context
>
class PushValue<unsigned int, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const unsigned int& v)
    {
        duk_push_int(ctx->context(), v);
    }
};


template<
    typename _Context
>
class PushValue<long, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value 
     */
    static void perform(_Context* ctx, const long& v)
    {
        duk_push_int(ctx->context(), v);
    }
};

template<
    typename _Context
>
class PushValue<unsigned long, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const unsigned long& v)
    {
        duk_push_int(ctx->context(), v);
    }
};

template<
    typename _Context
>
class PushValue<long long, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const long long& v)
    {
        duk_push_int(ctx->context(), static_cast<int>(v));
    }
};

template<
    typename _Context
>
class PushValue<unsigned long long, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const unsigned long long& v)
    {
        duk_push_int(ctx->context(), static_cast<int>(v));
    }
};

template<
    typename _Context
>
class PushValue<float, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const float& v)
    {
	    // ReSharper disable once CppIdenticalOperandsInBinaryExpression
	    if (v != v)
        {
            duk_push_nan(ctx->context());
        }
        duk_push_number(ctx->context(),static_cast<double>(v));
    }
};


template<
    typename _Context
>
class PushValue<double, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const double& v)
    {
	    // ReSharper disable once CppIdenticalOperandsInBinaryExpression
	    if (v != v)
        {
            duk_push_nan(ctx->context());
        }
        duk_push_number(ctx->context(),static_cast<double>(v));
    }
};

template<
    typename _Context
>
class PushValue<long double, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const long double& v)
    {
	    // ReSharper disable once CppIdenticalOperandsInBinaryExpression
	    if (v != v)
        {
            duk_push_nan(ctx->context());
        }
        duk_push_number(ctx->context(),static_cast<double>(v));
    }
};

template<
    typename _Context
>
class PushValue<const char*, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const char*& v)
    {
        duk_push_string(ctx->context(), v);
    }
};


template<
    typename _Context
>
class PushValue<char*, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const char*& v)
    {
        duk_push_string(ctx->context(), v);
    }
};

template<
    typename _Context
>
class PushValue<std::string, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const std::string& v)
    {
        duk_push_string(ctx->context(), v.c_str());
    }
};


/*! Performs pushing value on stack for every type of value
 */
template<
    typename _Value,
    typename _Context
>
class PushValue<dukpp03::Maybe<_Value>, _Context>
{
public:
    /*! Performs pushing value 
        \param[in] ctx context
        \param[in] v value
     */
    static void perform(_Context* ctx, const dukpp03::Maybe<_Value>& v)
    {        
        if (v.exists())
        {
            dukpp03::PushValue<_Value,_Context>::perform(ctx, v.value());
        }
        else
        {
            duk_push_null(ctx->context());
        }
    }
};

}
