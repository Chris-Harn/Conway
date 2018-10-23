#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>

class Board;

class Game {
public:
	bool init( int boardWidth, int boardHeight, int screenWidth, int screenHeight );
	void render();
	void update();
	void handleEvents();
	void clean();
	
	~Game();
	bool running() { return m_bRunning; }
	void exit() { m_bRunning = false; }
	bool gamePaused();
	void changePause();
	static Game* Instance() {
		if( s_pInstance == 0 ) {
			s_pInstance = new Game();
			return s_pInstance;	
		}
		return s_pInstance;
	}
private:
	Game();
	Board *m_pboard;
	bool m_bRunning;
	bool m_bPaused;
	static Game* s_pInstance;
	SDL_Renderer *m_prenderer;
	SDL_Window *m_pwindow;
};

typedef Game TheGame;

#endif
