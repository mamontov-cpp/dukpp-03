/*! \file constructor.h
     
    Defines a simple defines for creating bindings for creating new QObject instances
 */
#pragma once
#include "callable.h"
#include "context.h"

namespace dukpp03
{

namespace qt
{

{{#variants}}

/*! Defines a wrapper for method, which returns nothing and receives {{argscount}} arguments
 */
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
class Constructor{{argscount}} : public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A local context
     */
    typedef dukpp03::qt::BasicContext _Context;
    /*! Constructs new object
     */
    Constructor{{argscount}}()
    {
    }
    /*! Returns copy of callable object 
        \return copy of callable object
     */
    virtual dukpp03::Callable<_Context>* clone() override
    {
        return new dukpp03::qt::Constructor{{argscount}}<_ClassName{{#has_args}}, {{/has_args}}{{#args}}_Arg{{number}}{{#not_last}}, {{/not_last}}{{/args}}>();
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override
    {
        return {{argscount}};
    }
    DUKPP03_CBC_{{argscount}}{{#has_args}}(0,{{#args}}_Arg{{number}}{{#not_last}},{{/not_last}}{{/args}}){{/has_args}}
    /*! Performs call of object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int _call(dukpp03::qt::BasicContext* c) override
    {
{{#args}}
        DUKPP03_MAYBE_FROM_STACK(_Arg{{number}}, {{number}}, {{number}}, {{numberp1}});
{{/args}}        
        _ClassName*  t = new  _ClassName{{#has_args}}({{#args}}_a{{number}}._(){{#not_last}}, {{/not_last}}{{/args}}){{/has_args}};
        c->pushVariant<_ClassName*>(dukpp03::qt::BasicContext::VariantUtils::makeFrom(t), dukpp03::qt::qobjectfinalizer);
        return 1;
    }
    /*! Can be inherited
     */
    virtual ~Constructor{{argscount}}() override
    {
    }   
};
{{/variants}}

struct qobject
{

{{#variants}}
/*! Register constructor as global function of context
    \return callable constructor
 */
template<
    typename _ClassName{{#has_args}},{{/has_args}}
{{#args}}{{#not_last}}    typename _Arg{{number}},{{/not_last}}{{#last}}    typename _Arg{{number}}{{/last}}
{{/args}}
>
static inline dukpp03::Callable<dukpp03::qt::BasicContext>* construct()
{
    dukpp03::Callable<dukpp03::qt::BasicContext>* c = new dukpp03::qt::Constructor{{argscount}}<_ClassName{{#has_args}}, {{/has_args}}{{#args}}{{#not_last}}_Arg{{number}}, {{/not_last}}{{#last}}_Arg{{number}}{{/last}}{{/args}}>();
    return c;
}

{{/variants}}

};


}

}
