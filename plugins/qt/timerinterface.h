/*! \file timerinterface.h
    
    Defines a timerinteface
 */
#include <QTime>

namespace dukpp03
{

namespace qt
{


struct TimerInterface
{
    typedef QTime Timer;

    /*! Restarts timer
        \param[in, out] t timer to be restarted
     */ 
    inline static void restart(QTime& t)
    {
        t.restart();
    }
    /*! Returns elapsed time for interface in ms
        \param[in] t timer
        \return elapsed time in milliseconds
     */
    inline static double elapsed(QTime& t)
    {
        return t.elapsed();
    }
};

}

}