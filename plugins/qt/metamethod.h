/*! \file metamethod.h
 
    Describes a callable metamethod
 */
#pragma once
#include "basiccontext.h"
#include <QMetaMethod>

namespace dukpp03
{
    
namespace qt
{

/*! A basic meta method, that could be called
 */    
class MetaMethod: public dukpp03::Callable<dukpp03::qt::BasicContext>
{
friend class MetaConstructor;
public:
    /*! Makes new meta method
        \param[in] index an index of method
        \param[in] m method
     */
    MetaMethod(int index, const QMetaMethod& m);
    /*! Could be inherited
     */
    virtual ~MetaMethod();
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual Callable<dukpp03::qt::BasicContext>* clone() override;
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments()  override;
    /*! Performs check, whether callable can be called, without actually calling an object in context
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(dukpp03::qt::BasicContext* c)  override;
    /*! Returns false
        \return false
     */
    virtual bool canBeCalledAsConstructor() override;
    /*! Performs actual function call
        \param[in] c context
     */
    virtual int _call(dukpp03::qt::BasicContext* c) override;
    /*! Returns name for meta-method
        \param[in] method a method
        \return name for method
     */
    static QString name(QMetaMethod method);
protected:
    /*! Checks first argument to be called
        \param[in] c context
        \return NULL if method cannot be called
     */
    QObject* checkThis(dukpp03::qt::BasicContext* c) const;
    /*! Converts stack to list of variants
        \param[in] c context
        \param[out] list a list of variant
        \return whether converting all of variants was successful
     */
    static bool stackToVariantList(dukpp03::qt::BasicContext* c, QVariantList& list);
    /*! Index of meta-method in source object
     */ 
    int m_index;
    /*! A new meta-method
     */  
    QMetaMethod m_method;
};

}

}
