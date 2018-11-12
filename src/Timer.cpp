#include "Timer.h"


/**************************************************
 *  Timer::Timer
 *  Purpose: Constructor.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Timer::Timer() : m_timerForRendering( SDL_GetTicks() ), m_timerForUpdatingBoard( SDL_GetTicks() ) {

}


/**************************************************
 *  Timer::~Timer
 *  Purpose: Empty deconstructor.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Timer::~Timer() {

}


/**************************************************
 *  Timer::init
 *  Purpose: Sets up delay for rendering, and 
 *  counting/updating tiles.
 *  Input: Time in milliseconds, Time in milliseconds.
 *  Return: None.
 *
 *************************************************/

void Timer::init( double delayForRendering, double delayForUpdatingBoard ) {
	m_delayForRendering = delayForRendering;
	m_delayForUpdatingBoard = delayForUpdatingBoard;
}


/**************************************************
 *  Timer::timeForRender
 *  Purpose: Checks time to update window context.
 *  Input: None.
 *  Return: bool (true) if longer than delay time.
 *  bool (false) if not longer than delay time.
 *
 *************************************************/

bool Timer::timeForRender() {
	if( ( SDL_GetTicks() - m_timerForRendering ) > m_delayForRendering ) {
		m_timerForRendering = SDL_GetTicks();
		return true;
	} else {
		return false;
	}
}


/**************************************************
 *  Timer::timeForUpdatingBoard
 *  Purpose: Checks if time to update board.
 *  Input: None.
 *  Return: bool (true) if longer than delay time.
 *  bool (false) if not longer than delay time.
 *
 *************************************************/

bool Timer::timeForUpdatingBoard() {
	if( ( SDL_GetTicks() - m_timerForUpdatingBoard ) > m_delayForUpdatingBoard ) {
		m_timerForUpdatingBoard = SDL_GetTicks();
		return true;
	} else {
		return false;
	}
}


/**************************************************
 *  Timer::pause
 *  Purpose: Pauses simulation for a specified 
 *  amount of time.
 *  Input: time in milliseconds.
 *  Return: None.
 *
 *************************************************/

void Timer::pause( double time ) {
	// time in milli seconds
	SDL_Delay( time );
}
