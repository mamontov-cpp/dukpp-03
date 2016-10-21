/*! \file test.h
    
    Returns simple derived object
 */
#pragma once
#include "test2.h"
#include <QObject>
#include <iostream>

/*! A simple test object
 */
struct Test: public QObject
{
    Q_OBJECT
public:
    /*! A value holder for test
     */
    struct ValueHolder
    {
        /*! A value holder
         */
        int Value;
        /*! Constructs new holder with default value
         */
        ValueHolder();
        /*! Constructs new holder
            \param[in] v value
         */
        ValueHolder(int v);
        /*! Prints value on screen
         */
        void printValue() const;
        /*! Returns value from holder
            \return value
         */ 
        int getValue() const;
    };

    Q_PROPERTY(int value READ getValue WRITE setValue)
    /*! A test object initializer value with 0
     */
    Q_INVOKABLE Test();
    /*! Initializes object with value
        \param[in] value a value
     */
    Q_INVOKABLE Test(int value);
    /*! Sets a value for test
        \param[in] value a value for test
     */
    void setValue(int value);
    /*! Returns a value
        \return value
     */
    int getValue();
    /*! Returns derived object
        \param[in] a
        \return constructed a
     */
    Q_INVOKABLE Test2* returnDerived(int a);
    /*! A test function, that returns a holder
        \return a holder
     */
    Q_INVOKABLE Test::ValueHolder returnHolder();
    /*! A test function, that returns a holder pointer
        \return a holder
     */
    Q_INVOKABLE Test::ValueHolder* returnHolderPtr();
    /*! Deletes a holder pointer
        \param[in] ptr pointer
     */
    static void deleteHolder(Test::ValueHolder* ptr);
    /*! Sets half of value
        \param[in] value1 a value
        \param[in] value2 a value
     */
    void setHalfOfValueFromSum(int value1, int value2);
public slots:    
    /*! Returns 3
        \return 3
     */
    int return3();
    /*! Sets half of value
        \param[in] value a value
     */
    void setHalfOfValue(int value);
public:
    int m_value;
};


Q_DECLARE_METATYPE(Test*)
Q_DECLARE_METATYPE(Test**)
Q_DECLARE_METATYPE(Test2*)
Q_DECLARE_METATYPE(Test::ValueHolder)
Q_DECLARE_METATYPE(Test::ValueHolder*)
Q_DECLARE_METATYPE(Test::ValueHolder**)
