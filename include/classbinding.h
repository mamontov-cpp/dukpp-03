/*! \file classbinding.h

    Defines a basic binding for class in context
 */
#pragma once
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include "callable.h"
#include "constructor.h"
#include "multimethod.h"
#include <cassert>

namespace dukpp03
{

/*! Defines a basic binding for class in context. Please note, that binding is being initialized 
    when it's FIRST time added into context, so if you change properties after adding it to class,
    it won't be initialized. 
    
    Uses vector, since iteration here used a much larger magnitude, then here
 */
template<
    typename _Context
>
class ClassBinding
{
public: 
    /*! A named multi-method
     */  
    typedef std::pair<std::string, dukpp03::MultiMethod<_Context>*> NamedMultiMethod;
    /*! A multi-method list
     */  
    typedef std::vector<NamedMultiMethod> MultiMethodList;
    /*! An accessor is a pair of callables
     */  
    typedef std::pair<dukpp03::MultiMethod<_Context>*, dukpp03::MultiMethod<_Context>* > Accessor;
    /*! A named accessor for binding
     */
    typedef std::pair<std::string, Accessor> NamedAccessor;
    /*! An acessor list for all of accessor
     */
    typedef std::vector<NamedAccessor> AccessorList;
    /*! Creates new empty binding
     */
    ClassBinding()
    {
    
    }
    /*! A class binding owns all of it's binding and destroys them automatically
     */
    virtual ~ClassBinding()
    {
        this->clear();
    }
    /*! Copies a class binding into current binding
        \param[in] o other binding
     */
    ClassBinding(const ClassBinding<_Context>& o)
    {
        this->copy(o);
    }
    /*! Assigns an operator binding to current class
        \param[in] o object
        \return self-reference
     */
    ClassBinding<_Context>&  operator=(const ClassBinding<_Context>& o)
    {
        this->destroy();
        this->copy(o);
        return *this;
    }
    /*! Clears a binding
     */
    void clear()
    {
        destroy(m_constructors);
        destroy(m_methods);
        destroy(m_accessors);
    }
    /*! Adds new callable as constructor
        \param[in] name a name for it
        \param[in] c callable
        \return a reference to c
     */
    dukpp03::Callable<_Context>* addConstructor(const std::string& name, dukpp03::Callable<_Context>* c)
    {
        insert(name, m_constructors, c);
        return c;
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor0<_Context, _ClassName>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor1<_Context, _ClassName, _Arg0>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor2<_Context, _ClassName, _Arg0, _Arg1>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor3<_Context, _ClassName, _Arg0, _Arg1, _Arg2>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor4<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor5<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor6<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor7<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor8<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor9<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor10<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor11<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10,
        typename _Arg11
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor12<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10,
        typename _Arg11,
        typename _Arg12
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor13<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10,
        typename _Arg11,
        typename _Arg12,
        typename _Arg13
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor14<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10,
        typename _Arg11,
        typename _Arg12,
        typename _Arg13,
        typename _Arg14
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor15<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14>());
    }
    /*! Adds new constructor for specified class
        \param[in] name a name for it
        \return reference to constructor
     */
    template<
        typename _ClassName,
        typename _Arg0,
        typename _Arg1,
        typename _Arg2,
        typename _Arg3,
        typename _Arg4,
        typename _Arg5,
        typename _Arg6,
        typename _Arg7,
        typename _Arg8,
        typename _Arg9,
        typename _Arg10,
        typename _Arg11,
        typename _Arg12,
        typename _Arg13,
        typename _Arg14,
        typename _Arg15     
    >
    dukpp03::Callable<_Context>* addConstructor(const std::string& name)
    {
        return addConstructor(name, new dukpp03::Constructor16<_Context, _ClassName, _Arg0, _Arg1, _Arg2, _Arg3, _Arg4, _Arg5, _Arg6, _Arg7, _Arg8, _Arg9, _Arg10, _Arg11, _Arg12, _Arg13, _Arg14, _Arg15>());
    }
    /*! Adds new callable as method
        \param[in] name a name for it
        \param[in] c callable
     */
    void addMethod(const std::string& name, dukpp03::Callable<_Context>* c)
    {
        insert(name, m_methods, c);
    }
    /*! Adds new callable pair as accessors. Note that both of them can be null
        \param[in] name a name for it
        \param[in] getter a getter for value
        \param[in] setter a setter for value
     */
    void addAccessor(const std::string& name, dukpp03::Callable<_Context>* getter,  dukpp03::Callable<_Context>* setter)
    {
        insert(name, m_accessors, getter, setter);
    }
    /*! Removes constructor from list, erasing it from memory
        \param[in] name a name for it
        \param[in] c a callable
     */
    void removeConstructor(const std::string& name, dukpp03::Callable<_Context>* c)
    {
        remove(name, m_constructors, c);
    }
    /*! Removes method from list, erasing it from memory
        \param[in] name a name for it
        \param[in] c a callable
     */
    void removeMethod(const std::string& name, dukpp03::Callable<_Context>* c)
    {
        remove(name, m_methods, c);
    }
    /*! Removes method from list, erasing it from memory
        \param[in] name a name for it
        \param[in] c1 a first callable
        \param[in] c2 a second callable     
     */
    void removeAccessor(const std::string& name, dukpp03::Callable<_Context>* c1, dukpp03::Callable<_Context>* c2)
    {
        remove(name, m_accessors, c1, c2);
    }
    /*! Registers a binding in context
        \param[in] c context
     */
    void registerInContext(_Context* c)
    {
        for(size_t i = 0; i < m_constructors.size(); i++)
        {
            c->registerCallable(m_constructors[i].first, m_constructors[i].second, false);
        }
    }

    /*! Unregisters a binding in context
        \param[in] c context
     */
    void unregisterInContext(_Context* c)
    {
        for(size_t i = 0; i < m_constructors.size(); i++)
        {
            c->unregisterGlobal(m_constructors[i].first);
        }
    }
    /*! Wraps value, setting methods for context
        \param[in] c context
     */
    virtual void wrapValue(_Context* c)
    {
        for(size_t i = 0; i < m_methods.size(); i++)
        {
            c->registerMutableProperty(m_methods[i].first, m_methods[i].second, false);
        }
        
        for(size_t i = 0; i < m_accessors.size(); i++)
        {
            c->registerAtribute(m_accessors[i].first, m_accessors[i].second.first, false, m_accessors[i].second.second, false);
        }

        if (m_prototype_function.size() != 0)
        {
            duk_bool_t result = duk_peval_string(c->context(), m_prototype_function.c_str());
            assert( result == 0);
            duk_set_prototype(c->context(), -2);
        }
    }

    /*! Sets a function, which should be used a prototype for objects, pushed on stack
        \param[in] fun a function
     */
    void setPrototypeFunction(const std::string& fun)
    {
        m_prototype_function = fun;
    }
protected:
    /*! Inserts a callable into multimethod list
        \param[in] name a name of callable
        \param[in] dest a destination list
        \param[in] c a callable
     */
    void insert(const std::string& name, MultiMethodList& dest, dukpp03::Callable<_Context>* c)
    {
        for(size_t i = 0; i < dest.size(); i++)
        {
            if (dest[i].first == name)
            {
                dest[i].second->add(c);
                return;
            }
        }
        dukpp03::MultiMethod<_Context>* m = new dukpp03::MultiMethod<_Context>();
        m->add(c);
        dest.push_back(std::make_pair(name, m));
    }
    
    /*! Inserts a callable into multimethod list
        \param[in] name a name of callable
        \param[in] dest a destination list
        \param[in] getter a getter
        \param[in] setter a setter
     */
    void insert(const std::string& name, AccessorList& dest, dukpp03::Callable<_Context>* getter, dukpp03::Callable<_Context>* setter)
    {
        for(size_t i = 0; i < dest.size(); i++)
        {
            if (dest[i].first == name)
            {
                dukpp03::MultiMethod<_Context>* g = dest[i].second.first;
                dukpp03::MultiMethod<_Context>* s = dest[i].second.second;
                if ((!g) && getter)
                {
                    g = new dukpp03::MultiMethod<_Context>();
                    dest[i].second.first = g;
                }
                if ((!s) && setter)
                {
                    s = new dukpp03::MultiMethod<_Context>();
                    dest[i].second.second = s;
                }
                if (getter)
                {
                    g->add(getter);
                }
                if (setter)
                {
                    g->add(setter);
                }
                return;
            }
        }
        dukpp03::MultiMethod<_Context>* g = NULL;
        if (getter)
        {
            g = new dukpp03::MultiMethod<_Context>();
            g->add(getter);
        }
        dukpp03::MultiMethod<_Context>* s = NULL;
        if (getter)
        {
            s = new dukpp03::MultiMethod<_Context>();
            s->add(setter);
        }
        dest.push_back(std::make_pair(name, std::make_pair(g, s)));
    }
    /*! Removes a callable from multimethod list
        \param[in] name a name of callable
        \param[in] src source
        \param[in] c callable
     */
    void remove(const std::string& name, MultiMethodList& src, dukpp03::Callable<_Context>* c)
    {
        for(size_t i = 0; i < src.list(); i++)
        {
            if (src[i].first == name)
            {
                if (src[i].second->remove(c))
                {
                    delete c;
                    if (src[i].second->count() == 0)
                    {
                        delete src[i].second;
                        src.erase(src.begin() + i);
                        --i;
                    }
                }
            }
        }
    }
    /*! Removes a callable from multimethod list
        \param[in] name a name of callable
        \param[in] src source
        \param[in] c callable
     */
    void remove(const std::string& name, AccessorList& src, dukpp03::Callable<_Context>* c)
    {
        for(size_t i = 0; i < src.list(); i++)
        {
            if (src[i].first == name)
            {
                if (src[i].second.first->remove(c))
                {
                    delete c;
                    if (src[i].second.first->count() == 0)
                    {
                        delete src[i].second.first;
                        src[i].second.first = NULL;
                    }
                }
                
                if (src[i].second.second->remove(c))
                {
                    delete c;
                    if (src[i].second.second->count() == 0)
                    {
                        delete src[i].second.second;
                        src[i].second.second = NULL;
                    }
                }
                
                if (src[i].second.first == NULL && src[i].second.second == NULL)
                {
                    src.erase(src.begin() + i);
                    --i;
                }
            }
        }
    }
    /*! Copies a class binding state into current binding
        \param[in] m a binding
     */
    void copy(const ClassBinding<_Context>& m)
    {
        copy(m_constructors, m.m_constructors);
        copy(m_methods, m.m_methods);
        copy(m_accessors, m.m_accessors);
        m_prototype_function = m.m_prototype_function;
    }
    /*! Copies source multimethod list to destination
        \param[in] dest destination
        \param[in] src source
     */
    void copy(MultiMethodList& dest, const MultiMethodList& src)
    {
        for(size_t i = 0; i < src.size(); i++)
        {
            dest.push_back(std::make_pair(src[i].first,  static_cast<dukpp03::MultiMethod<_Context>* >(src[i].second->clone())));
        }
    }
    /*! Copies source multimethod list to destination
        \param[in] dest destination
        \param[in] src source
     */
    void copy(AccessorList& dest, const AccessorList& src)
    {
        for(size_t i = 0; i < src.size(); i++)
        {
            const Accessor& acc = src[i].second;
            Accessor newacc = acc;
            if (newacc.first)
            {
                newacc.first = static_cast<dukpp03::MultiMethod<_Context>* >(newacc.first->clone());
            }
            if (newacc.second)
            {
                newacc.second = static_cast<dukpp03::MultiMethod<_Context>* >(newacc.second->clone());
            }
            dest.push_back(std::make_pair(src[i].first, newacc));
        }
    }
    
    /*! Destructs a list
        \param[in] dest a list
     */
    void destroy(MultiMethodList& dest)
    {
        for(size_t i = 0; i < dest.size(); i++)
        {
            delete dest[i].second;
        }
        dest.clear();
    }
    
    /*! Destructs a list
        \param[in] dest  a list
     */
    void destroy(AccessorList& dest)
    {
        for(size_t i = 0; i < dest.size(); i++)
        {
            delete dest[i].second.first;
            delete dest[i].second.second;
        }
        dest.clear();
    }
    /*! A constructor list for bindings
     */
    MultiMethodList m_constructors;
    /*! A methods list for binding
     */
    MultiMethodList m_methods;
    /*! An accessor list for binding
     */
    AccessorList m_accessors;
    /*! A function, which should be evaluated to set prototype for wrapped object
     */
    std::string m_prototype_function;
};




}
