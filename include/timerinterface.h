/*! \file timerinterface.h
	
	Defines a generic interface for interacting with timers
 */
#pragma once

namespace dukpp03
{

/*! A generic interface for timer implementation
 */
template<
	typename _Timer
>	
struct TimerInterface
{
	/*! An inner timer
	 */
	typedef _Timer Timer;

	/*! Restarts timer
		\param[in, out] t timer to be restarted
	 */ 
	void restart(_Timer& t);
	/*! Returns elapsed time for interface in ms
		\param[in] t timer
		\return elapsed time in milliseconds
	 */
	double elapsed(Timer& t);
};	

}