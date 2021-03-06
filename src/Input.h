#ifndef __INPUT__
#define __INPUT__

#include <vector>
#include <SDL2/SDL.h>

/**************************************************
 *  Input Handler
 *  Purpose: Collects keyboard and mouse input to 
 *  perform various functions on the board: pause, 
 *  flip tile, draw shapes, and start simulation.
 *
 *************************************************/

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class Input {
public:
	void init();
	void update();
	void clean();

	static Input* instance() {
		if( s_pinstance == 0 ) {
			s_pinstance = new Input();
		}
		return s_pinstance;
	}

	bool onKeyDown( SDL_Scancode key );
private:
	Input();

	void onKeyDown();
	void onKeyUp();

	void onMouseMove( SDL_Event& event );
	void onMouseButtonDown( SDL_Event& event );
	void onMouseButtonUp( SDL_Event& event );
	bool getMouseButtonState( int buttonNumber );
	
	static Input* s_pinstance;
	const Uint8* m_keystates;
	std::vector<bool> m_mouseButtonStates;
};

typedef Input TheInputHandler;
#endif
