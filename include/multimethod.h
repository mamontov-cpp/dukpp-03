/*! \file multimethod.h
    

    Contains definition of multi-method, which can be called as constructor and object.
 */
#pragma once
#include "callable.h"
#include <vector>
#include <algorithm>
#include <iostream>

namespace dukpp03
{

/*! A context-dependent callable
 */
template<
   typename _Context
>
class MultiMethod: public dukpp03::Callable<_Context>
{
public:
    /*! Constructs empty multi-method
     */
    MultiMethod()
    {
        
    }
    /*! Copies other multi-method
        \param[in] m multi-method
     */
    MultiMethod(const dukpp03::MultiMethod<_Context>& m)
    {
        this->copy(m);
    }
    /*! Copies other multi-method
        \param[in] m multi-method
     */
    MultiMethod& operator=(const dukpp03::MultiMethod<_Context>& m)
    {
        this->clear();
        this->copy(m);
    }
    /*! Destructs multi-method
     */
    ~MultiMethod()
    {
        this->clear();
    }
    /*! Adds new callable to multi-method
        \param[in] callable a callable
     */
    void add(Callable<_Context>* callable)
    {
        if (std::find(m_callables.begin(), m_callables.end(), callable) != m_callables.end())
        {
            return;
        }
        m_callables.push_back(callable);
    }
    /*! Removes callable from list
        \param[in] callable
        \return true if callable was removed
     */
    bool remove(Callable<_Context>* callable)
    {
        typename std::vector<Callable<_Context*> >::iterator it = std::find(m_callables.begin(), m_callables.end(), callable);
        if (it != m_callables.end())
        {
            m_callables.erase(it);
            return true;
        }
        return false;
    }
    /*! Returns whether it could be called as constructor
        \return true if can
     */
    virtual bool canBeCalledAsConstructor()
    {
        for(size_t i = 0; i < m_callables.size(); i++)
        {
            if (m_callables[i]->canBeCalledAsConstructor())
            {
                return true;
            }
        }
        return false;
    }
    /*! Returns whether it could be called as function
        \return true if can
     */
    virtual bool canBeCalledAsFunction()
    {
        for(size_t i = 0; i < m_callables.size(); i++)
        {
            if (m_callables[i]->canBeCalledAsFunction())
            {
                return true;
            }
        }
        return false;
    }
    /*! Performs check, whether callable can be called, without actually calling an object in context
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(_Context* c)
    {
        if (duk_is_constructor_call(c->context()))
        {
            if (this->canBeCalledAsConstructor() == false)
            {
                return std::make_pair(0, false);
            }
        }
        else
        {
            if (this->canBeCalledAsFunction() == false)
            {
                return std::make_pair(0, false);              
            }
        }
        std::pair<int, bool> result = std::make_pair(0, false);
        Callable<_Context>* ptr = NULL;
        this->getCandidate(c, result, &ptr);
        return result;
    }
    /*! Performs call on object, using specified context
        \param[in] c context
        \return count of values on stack, placed by functions
     */
    virtual int call(_Context* c)
    {
        if (duk_is_constructor_call(c->context()))
        {
            if (this->canBeCalledAsConstructor() == false)
            {
                c->throwFunctionCallShouldNotBeCalledAsConstructor();
                return 0;
            }
        }
        else
        {
            if (this->canBeCalledAsFunction() == false)
            {
                c->throwFunctionCallShouldBeACalledOnlyAsConstructor();
                return 0;               
            }
        }
        
        std::pair<int, bool> result = std::make_pair(0, false);
        Callable<_Context>* ptr = NULL;
        this->getCandidate(c, result, &ptr);
        // std::cout << result.first << ", " << result.second << "\n";
        try
        {
            if (ptr)
                return ptr->call(c);
            return 0;
        }
        catch(dukpp03::ArgumentException e)
        {
            return 0;
        }
        catch(...)
        {
            c->throwCaughtException();
            return 0;
        }
        return 0;
    }
    /*! Returns amount of callables in multi-method
     */ 
    int count() const
    {
        return m_callables.size();
    }
    /*! Must return copy of callable object
        \return copy of callable object
     */
    virtual Callable<_Context>* clone()
    {
        return new MultiMethod<_Context>(*this);
    }
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()
    {
        if (m_callables.size() == 0)
        {
            return 0;
        }
        int result = 0;
        bool first = true;
        for(size_t i = 0; i < m_callables.size(); i++)
        {
            int args = m_callables[i]->requiredArguments();
            if ((args < result) || first)
            {
                first = false;
                result = args;
            }
        }
        return result;
    }
    /*! Clears current multi-method, erasing all children
     */
    void clear()
    {
        for(size_t i = 0; i < m_callables.size(); i++)
        {
            delete m_callables[i];
        }
        m_callables.clear();
    }
protected:
    /*! Returns candidate for call for multi-method
        \param[in]  c context
        \param[out] result a result of seeking for candidate
        \param[out] callback a callback, which can be called upon
     */
    void getCandidate(_Context* c, std::pair<int, bool>& result, dukpp03::Callable<_Context>** callback)
    {
        result = std::make_pair(0, false);
        bool first = true;
        for(size_t i = 0; i < m_callables.size(); i++)
        {
            std::pair<int, bool> candidate = m_callables[i]->canBeCalled(c);
            // std::cout << "Candidate" << i << ": " << candidate.first << ", " << candidate.second << "\n";
            // If candidate matched more than current, than it should be used, but watch out for first match
            if ((candidate.first > result.first) || first)
            {
                first = false;
                result = candidate;
                *callback = m_callables[i];
            }
        }
    }
    /*! Copies multi-method state into self
        \param[in] m multi-method
     */
    void copy(const dukpp03::MultiMethod<_Context>& m)
    {
        for(size_t i = 0; i < m.m_callables.size(); i++)
        {
            m_callables.push_back(m.m_callables[i]->clone());
        }
    }
    /*! A list of methods, that could be called
     */
    std::vector<dukpp03::Callable<_Context>* > m_callables;
};



}