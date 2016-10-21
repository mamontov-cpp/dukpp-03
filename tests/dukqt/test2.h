/*! \file test2.h
 
    A second test object
 */
#pragma once
#include <QObject>

/*! A second test object
 */
struct Test2: public QObject
{
    Q_OBJECT
public:
    /*! A second test object
     */
    Test2();
    /*! A second test object
        \param[in] value a value
     */
    Test2(int value);    
public slots:
    /*! Returns stored value
        \return stored value
     */
    int get();    
protected:
    /*! A inner test value
     */
    int m_value;
};
