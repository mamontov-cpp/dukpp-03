/*! \file metapropertyaccessor.h

    Describes an accessor for metaproperty, which can be used to access
    properties of QObject.
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
class MetaPropertyAccessor: public dukpp03::Callable<dukpp03::qt::BasicContext>
{
public:
    /*! A mode of work for accessor
     */
    enum class Mode: int
    {
        MPAM_Get, //!< The accessor will behave as getter
        MPAM_Set, //!< The accessor will behave as setter
    };
    /*! Makes new meta property accessor
        \param[in] index an index of method
        \param[in] m method
        \param[in] mode of work for accessor
     */
    MetaPropertyAccessor(
        int index,
        const QMetaProperty& m,
        dukpp03::qt::MetaPropertyAccessor::Mode mode
    );
    /*! Could be inherited
     */
    virtual ~MetaPropertyAccessor() override;
    /*! Returns copy of callable object
        \return copy of callable object
     */
    virtual Callable<dukpp03::qt::BasicContext>* clone() override;
    /*! Returns count of required arguments
        \return count of required arguments
     */
    virtual int requiredArguments() override;
    /*! Performs check, whether callable can be called, without actually calling an object in context
        \param[in] c context
        \return pair
     */
    virtual std::pair<int, bool> canBeCalled(dukpp03::qt::BasicContext* c) override;
    /*! Returns false
        \return false
     */
    virtual bool canBeCalledAsConstructor() override;
    /*! Performs actual function call
        \param[in] c context
     */
    virtual int _call(dukpp03::qt::BasicContext* c) override;
protected:
    /*! Checks first argument to be called
        \param[in] c context
        \return NULL if method cannot be called
     */
    QObject* checkThis(dukpp03::qt::BasicContext* c) const;
    /*! Index of meta-property in source object
     */
    int m_index;
    /*! A meta property
     */
    QMetaProperty m_property;
    /*! A mode for accessor
     */
    dukpp03::qt::MetaPropertyAccessor::Mode m_mode;
};

}

}
