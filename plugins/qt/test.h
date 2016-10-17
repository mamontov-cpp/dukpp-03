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

	inline Test(const Test& o)
    {
        
    }

	inline Test(int a)
    {
	    
    }

	Test& operator=(const Test&)
	{
		return *this;
	}

	inline void speak()
    {
	    std::cout << "I am test";
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
