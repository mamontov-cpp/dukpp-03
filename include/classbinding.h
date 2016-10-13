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
    ~ClassBinding()
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
protected:
    /*! Inserts a callable into multimethod list
        \param[in] name a name of callable
        \param[in] dest a destination list
        \param[in] c a callable
     */
    void insert(const std::string& name, MultiMethodList& dest, dukpp03::Callable<_Context>* c)
    {
        for(size_t i = 0; i < dest.list(); i++)
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
        \param[in] getter a getter
        \param[in] setter a setter
        \param[in] c a callable
     */
    void insert(const std::string& name, AccessorList& dest, dukpp03::Callable<_Context>* getter, dukpp03::Callable<_Context>* setter)
    {
        for(size_t i = 0; i < dest.list(); i++)
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
            g->add(getter);
        }
        dukpp03::MultiMethod<_Context>* s = NULL;
        if (getter)
        {
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
    }
    /*! Copies source multimethod list to destination
        \param[in] dest destination
        \param[in] src source
     */
    void copy(MultiMethodList& dest, const MultiMethodList& src)
    {
        for(size_t i = 0; i < src.size(); i++)
        {
            dest.push_back(std::make_pair(src[i].first, src[i].second->clone()));
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
                newacc.first = newacc.first->clone();
            }
            if (newacc.second)
            {
                newacc.second = newacc.second->clone();
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
};




}