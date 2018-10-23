#ifndef __INPUT__
#define __INPUT__

#include <vector>
#include <SDL2/SDL.h>

enum mouse_buttons {
	LEFT = 0,
	MIDDLE = 1,
	Right = 2
};
class Input {
public:
	void update();
	void clean();

	static Input* Instance() {
		if( s_pInstance == 0 ) {
			s_pInstance = new Input();
		}
		return s_pInstance;
	}

private:
	Input();
	~Input();

	void onKeyDown();
	void onKeyUp();

	void onMouseMove( SDL_Event& event );
	void onMouseButtonDown( SDL_Event& event );
	void onMouseButtonUp( SDL_Event& event );
	
	static Input* s_pInstance;
	std::vector<bool> m_mouseButtonStates;
};

typedef Input TheInputHandler;
#endif
