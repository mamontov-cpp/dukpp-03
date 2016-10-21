#pragma once
#include "test2.h"
#include <QObject>
#include <iostream>

struct Test: public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(int x READ getX WRITE setX)

    Q_INVOKABLE inline Test()
    {
        
    }

    Q_INVOKABLE inline Test(int a)
    {
        
    }

    inline void speak()
    {
        std::cout << "Test::speak() says: I am test\n";
    }

    /*! A test class
     */
    Q_INVOKABLE Test2* slot(int a)
    {
        return new Test2(a);
    }

    /*! A test class
     */
    Q_INVOKABLE void slot33(int a)
    {
        std::cout << "void Test::slot33()\n";
    }

    inline void setX(int x)
    {
        m_x = x;
    }

    inline int getX()
    {
        return m_x;
    }

public slots:    
    int slot2()
    {
        std::cout << "int Test::slot2()\n";
        return 0;
    }
    
    void slot3()
    {
        std::cout << "void Test::slot3()\n";        
    }
    
    void slotx(int a, long b, const QString& c, int d)
    {
        std::cout << "void Test::slotx()\n";        
    }
public:
    int m_x;
};


