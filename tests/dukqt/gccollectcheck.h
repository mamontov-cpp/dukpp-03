/*! \file gccollectcheck.h
 *
 *  A simple object, that increment counter, when destroyed
 */
#pragma once
#include <QObject>

/*! A simple object, that increment counter, when destroyed
 */
class GCCollectCheck: public QObject
{
Q_OBJECT
public: 
    /*! Creates object
     */
    GCCollectCheck();
    /*!  Can be inherited. Actually increments counter fields
     */  
    virtual ~GCCollectCheck();
    /*! Clears collection counter
     */
    static void clearCounter();
    /*! A number, that indicated how many times object is collected
     */
    static int counter;
};

