/*! \file timerinterface.h
    
    Defines a timerinteface
 */
#include <QElapsedTimer>

namespace dukpp03
{

namespace qt
{


struct TimerInterface
{
    typedef QElapsedTimer Timer;

    /*! Restarts timer
        \param[in, out] t timer to be restarted
     */ 
    inline static void restart(QElapsedTimer& t)
    {
        t.restart();
    }
    /*! Returns elapsed time for interface in ms
        \param[in] t timer
        \return elapsed time in milliseconds
     */
    inline static double elapsed(QElapsedTimer& t)
    {
        return t.elapsed();
    }
};

}

}