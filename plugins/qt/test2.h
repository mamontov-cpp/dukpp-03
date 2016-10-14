#pragma once
#include <QObject>

struct Test2: public QObject
{
    Q_OBJECT
public:
    inline Test2()
    {
        
    }
    inline Test2(int a) : m_a(a)
    {
        
    }
    int m_a;
public slots:
    /*! A test class
     */
    int slot(int a)
    {
        return 22 + a;
    };
};
