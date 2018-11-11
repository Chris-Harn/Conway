#include "Timer.h"

Timer::Timer() : m_timerForRendering( SDL_GetTicks() ), m_timerForUpdatingBoard( SDL_GetTicks() ) {

}

Timer::~Timer() {

}

void Timer::init( double delayForRendering, double delayForUpdatingBoard ) {
	m_delayForRendering = delayForRendering;
	m_delayForUpdatingBoard = delayForUpdatingBoard;
}

bool Timer::timeForRender() {
	if( ( SDL_GetTicks() - m_timerForRendering ) > m_delayForRendering ) {
		m_timerForRendering = SDL_GetTicks();
		return true;
	} else {
		return false;
	}
}

bool Timer::timeForUpdatingBoard() {
	if( ( SDL_GetTicks() - m_timerForUpdatingBoard ) > m_delayForUpdatingBoard ) {
		m_timerForUpdatingBoard = SDL_GetTicks();
		return true;
	} else {
		return false;
	}
}

void Timer::pause( double time ) {
	// time in milli seconds
	SDL_Delay( time );
}
