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
};
