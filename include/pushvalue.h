/*! \file pushvalue.h
    

    Describes an operations, that could be used to push value on a stackof Duktape
 */
#pragma once
#include "context.h"
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const _Value& v, bool persistent)
    {
        if (persistent)
        {
            ctx->pushPersistentVariant(_Context::VariantUtils::template makeFrom(v));
        }
        ctx->pushVariant(_Context::VariantUtils::template makeFrom(v));
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const bool& v, bool persistent)
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const char& v, bool persistent)
    {
        char buffer[2] = {v, 0};
        duk_push_string(ctx->context(), buffer);
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const unsigned char& v, bool persistent)
    {
        char buffer[2] = {v, 0};
        duk_push_string(ctx->context(), buffer);
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const int& v, bool persistent)
    {
        duk_push_int(ctx->context(), v);
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const float& v, bool persistent)
    {
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const double& v, bool persistent)
    {
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const char*& v, bool persistent)
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const char*& v, bool persistent)
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
        \param[in] persistent whether value should be in persistent stack 
     */
    static void perform(_Context* ctx, const std::string& v, bool persistent)
    {
        duk_push_string(ctx->context(), v.c_str());
    }
};

}
