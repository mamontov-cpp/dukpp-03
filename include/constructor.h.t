/*! \file constructor.h
     
    Defines a simple defines for creating bindings for creating new objects
 */
#pragma once
#include "callable.h"
#include "decay.h"
#include "getvalue.h"
#include "pushvalue.h"
#include "context.h"

namespace dukpp03
{

{{#variants}}

/*! Defines a wrapper for method, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _Context,
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class Constructor{{argscount}} : public dukpp03::Callable
{
public:
    /*! Constructs new object
     */
    Constructor{{argscount}}()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable* clone()
    {
        return new dukpp03::Constructor{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        return {{argscount}};
    }
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(dukpp03::AbstractContext* ctx)
    {
        _Context* c = reinterpret_cast<_Context*>(ctx);
        if (c->getTop() != {{argscount}})
        {
            c->throwInvalidArgumentCountError({{argscount}}, c->getTop());
            return 0;
        }
{{#args}}
        dukpp03::Maybe< typename dukpp03::Decay<_Arg{{number}}>::Type > _a{{number}} = dukpp03::GetValue< typename dukpp03::Decay<_Arg{{number}}>::Type, _Context >::perform(c, {{number}});
{{/args}}{{#args}}      
        if (_a{{number}}.exists() == false) 
        {
            std::string name = _Context::template typeName< _Arg{{number}} >();
            c->throwInvalidTypeError({{numberp1}}, name);
            return 0;
        }
        {{/args}}
        
        try
        {
            _ClassName  t{{#has_args}}({{#args}}_a{{number}}.mutableValue(){{#not_last}}, {{/not_last}}{{/args}}){{/has_args}};
            dukpp03::PushValue<_ClassName, _Context>::perform(c, t, false);
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~Constructor{{argscount}}()
    {
    }   
};
{{/variants}}

template<
    typename _Context
>
struct register_constructor
{

{{#variants}}
/*! Register constructor as global function of context
    \param[in] ctx context
    \param[in] prop property name
 */
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline void in_context(_Context* ctx, const std::string& prop)
{
    dukpp03::Callable* c = new Constructor{{argscount}}<_Context, _ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>();
    ctx->registerCallable(prop, c);
}

{{/variants}}

};

}
