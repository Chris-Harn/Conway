#ifndef __TIMER__
#define __TIMER__

#include <SDL2/SDL.h>

class Timer {
public:
	Timer();
	~Timer();
	void init( double delayForRendering, double delayForUpdatingBoard );
	bool timeForRender();
	bool timeForUpdatingBoard();

private:
	Uint32 m_timerForRendering;
	Uint32 m_timerForUpdatingBoard;
	double m_delayForRendering;
	double m_delayForUpdatingBoard;
};

#endif
