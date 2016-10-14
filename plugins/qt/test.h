#pragma once
#include "test2.h"
#include <QObject>

struct Test: public QObject
{
    Q_OBJECT
public:
    inline Test()
    {
        
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
        
    }
    
    void slot3()
    {
        
    }
    
    void slotx(int a, long b, const QString& c, int d)
    {
        
    }
};
