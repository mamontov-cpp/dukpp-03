#pragma once
#include "test2.h"
#include <QObject>
#include <iostream>

struct Test: public QObject
{
    Q_OBJECT
public:
    inline Test()
    {
        
    }

	inline Test(int a)
    {
	    
    }

	inline void speak()
    {
	    std::cout << "Test::speak() says: I am test\n";
    }
public slots:
    /*! A test class
     */
    Q_INVOKABLE Test2* slot(int a)
    {
        return new Test2(a);
    }
    
    int slot2()
    {
        return 0;
    }
    
    void slot3()
    {
        
    }
    
    void slotx(int a, long b, const QString& c, int d)
    {
        
    }
};
