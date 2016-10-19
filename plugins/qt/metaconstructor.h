/*! \file metaconstructor.h
 
    Defines a constructor, which calls on metamethod, specified inner
 */
#pragma once
#include "basiccontext.h"
#include <QMetaMethod>


namespace dukpp03
{
    
namespace qt
{

/*! A meta constructor, that could create new object via meta method call
 */     
class MetaConstructor: public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! Makes new meta method
        \param[in] mo meta object
        \param[in] m method
     */
    MetaConstructor(const QMetaObject* mo, const QMetaMethod& m);
    /*! Could be inherited
     */
    virtual ~MetaConstructor();
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual Callable<dukpp03::qt::BasicContext>* clone();
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments();
    /*! Performs check, whether callable can be called, without actually calling an object in context
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(dukpp03::qt::BasicContext* c);
    /*! Returns false
        \return false
     */
    virtual bool canBeCalledAsFunction();       
    /*! Performs actual function call
        \param[in] c context
     */
    virtual int _call(dukpp03::qt::BasicContext* c);
protected:
    /*! A meta object to be created
     */ 
    const QMetaObject* m_meta_object;
    /*! A new metametod
     */  
    QMetaMethod m_method;
};

}

}


