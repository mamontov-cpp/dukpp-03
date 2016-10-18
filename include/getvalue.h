/*! \file getvalue.h
    

    Describes an operations, that could be used to get value from a stack of
    operations of Duktape
 */
#pragma once
#include "context.h"
#include "maybe.h"
#include <string>
#include <iostream>

namespace dukpp03
{

namespace internal
{

template<
    typename _Value,
    typename _Context
>
class TryGetValueFromObject
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \param[out] result an output value. Won't be changed if result exists, will be set to result otherwise
    \return a value if it exists, otherwise empty maybe
 */
static void perform(_Context* ctx, duk_idx_t pos, dukpp03::Maybe<_Value>& result)
{
    if (duk_is_object(ctx->context(), pos))
    {
       duk_get_prop_string(ctx->context(), pos, DUKPP03_VARIANT_PROPERTY_SIGNATURE);
        if (duk_is_pointer(ctx->context(), -1))
        {
            void* ptr = duk_to_pointer(ctx->context(), -1);
            typename _Context::Variant * v = reinterpret_cast<typename _Context::Variant *>(ptr);
            if (v)
            {
                result = _Context::template valueFromVariant<_Value>(v);
                if (result.exists() == false)
                {
                    result = _Context::template valueAddressFromVariant<_Value>(v);
                }
            }
        }
        duk_pop(ctx->context());
    }
}

};

}

/*! Performs getting value from a stack for every type of value
 */
template<
    typename _Value,
    typename _Context
>
class GetValue
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<_Value> perform(_Context* ctx, duk_idx_t pos)
{
    dukpp03::Maybe<_Value> result;
    dukpp03::internal::TryGetValueFromObject<_Value, _Context>::perform(ctx, pos, result);
    if (result.exists() == false)
    {
        dukpp03::Maybe<_Value*> result2;
        dukpp03::internal::TryGetValueFromObject<_Value*, _Context>::perform(ctx, pos, result2);
        if (result2.exists())
        {
            result.setReference(result2.value());
        }
    }
    return result;
}

};


template<    
    typename _Context
>
class GetValue<bool, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<bool> perform(_Context* ctx, duk_idx_t pos)
{
    dukpp03::Maybe<bool> result;
    if (duk_is_boolean(ctx->context(), pos))
    {
        result.setValue(duk_to_boolean(ctx->context(), pos) > 0);
    } 
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(duk_to_number(ctx->context(), pos) > 0);
    } 
    else
    {
        dukpp03::internal::TryGetValueFromObject<bool, _Context>::perform(ctx, pos, result);
    }
    return result;
}

};

template<    
    typename _Context
>
class GetValue<char, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<char> perform(_Context* ctx, duk_idx_t pos)
{
    dukpp03::Maybe<char> result;
    dukpp03::Maybe<std::string> tmp = dukpp03::GetValue<std::string, _Context>::perform(ctx, pos);
    if (tmp.exists())
    {
        if (tmp.value().size() == 1) {
            result.setValue(tmp.value()[0]);
        }
    }
    if (!result.exists())
    {
        dukpp03::Maybe<int> tmp2 = dukpp03::GetValue<int, _Context>::perform(ctx, pos);
        if (tmp2.exists())
        {
            result.setValue(static_cast<char>(tmp2.value()));
        }        
    }
    return result;
}

};



template<    
    typename _Context
>
class GetValue<unsigned char, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<unsigned char> perform(_Context* ctx, duk_idx_t pos)
{
    dukpp03::Maybe<unsigned char> result;
    dukpp03::Maybe<std::string> tmp = dukpp03::GetValue<std::string, _Context>::perform(ctx, pos);
    if (tmp.exists())
    {
        if (tmp.value().size() == 1) {
            result.setValue(static_cast<unsigned char>(tmp.value()[0]));
        }
    }
    if (!result.exists())
    {
        dukpp03::Maybe<int> tmp2 = dukpp03::GetValue<int, _Context>::perform(ctx, pos);
        if (tmp2.exists())
        {
            result.setValue(static_cast<unsigned char>(tmp2.value()));
        }
    }
    return result;
}

};

template<    
    typename _Context
>
class GetValue<std::string, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<std::string> perform(
    _Context* ctx, 
    duk_idx_t pos
)
{
    dukpp03::Maybe<std::string> result;
    if (duk_is_string(ctx->context(), pos))
    {
        result.setValue(duk_to_string(ctx->context(), pos));
    }
    return result;
}

};


#define DEFINE_GET_VALUE_AS_CAST_FROM_INT( TYPE )   \
template<                                           \
    typename _Context                               \
>                                                   \
class GetValue< TYPE , _Context>                    \
{                                                   \
public:                                             \
static dukpp03::Maybe< TYPE > perform(              \
    _Context* ctx,                                  \
    duk_idx_t pos                                   \
)                                                   \
{                                                   \
    dukpp03::Maybe< TYPE > result;                                                                    \
    if (duk_is_number(ctx->context(), pos))                                                           \
    {                                                                                                 \
        result.setValue(static_cast< TYPE >(duk_to_int(ctx->context(), pos)));                        \
    }                                                                                                 \
    if (!result.exists())                                                                             \
    {                                                                                                 \
        dukpp03::internal::TryGetValueFromObject< TYPE , _Context>::perform(ctx, pos, result);        \
    }                                                                                                 \
    return result;                                                                                    \
}                                                                                                     \
};                                                                                                    


DEFINE_GET_VALUE_AS_CAST_FROM_INT(short)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(unsigned short)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(int)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(unsigned int)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(long)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(unsigned long)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(long long)
DEFINE_GET_VALUE_AS_CAST_FROM_INT(unsigned long long)

#undef DEFINE_GET_VALUE_AS_CAST_FROM_INT

template<    
    typename _Context
>
class GetValue<float, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<float> perform(
    _Context* ctx, 
    duk_idx_t pos
)
{
    dukpp03::Maybe<float> result;
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(static_cast<float>(duk_to_number(ctx->context(), pos)));
    }
    if (!result.exists())
    {
        dukpp03::internal::TryGetValueFromObject<float, _Context>::perform(ctx, pos, result);
    }
    return result;
}

};

template<    
    typename _Context
>
class GetValue<double, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<double> perform(
    _Context* ctx, 
    duk_idx_t pos
)
{
    dukpp03::Maybe<double> result;
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(duk_to_number(ctx->context(), pos));
    }
    if (!result.exists())
    {
        dukpp03::internal::TryGetValueFromObject<double, _Context>::perform(ctx, pos, result);
    }
    return result;
}

};



template<    
    typename _Context
>
class GetValue<long double, _Context>
{
public:
/*! Performs getting value from stack 
    \param[in] ctx context
    \param[in] pos index for stack
    \return a value if it exists, otherwise empty maybe
 */
static dukpp03::Maybe<long double> perform(
    _Context* ctx, 
    duk_idx_t pos
)
{
    dukpp03::Maybe<long double> result;
    if (duk_is_number(ctx->context(), pos))
    {
        result.setValue(duk_to_number(ctx->context(), pos));
    }
    if (!result.exists())
    {
        dukpp03::internal::TryGetValueFromObject<long double, _Context>::perform(ctx, pos, result);
    }
    return result;
}

};


}

