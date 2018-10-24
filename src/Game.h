#ifndef __GAME__
#define __GAME__

#include <SDL2/SDL.h>

class Board;

class Game {
public:
	bool init( const int boardWidth, const int boardHeight );
	void render();
	void update();
	void handleEvents();
	void clean();
	
	bool running() { return m_brunning; }
	bool gamePaused();
	void pauseBoard();
	void unpauseBoard();
	void exit() { m_brunning = false; }
	static Game* Instance() {
		if( s_pInstance == 0 ) {
			s_pInstance = new Game();
			return s_pInstance;	
		}
		return s_pInstance;
	}

private:
	Game();
	~Game();
	Board *m_pboard;
	bool m_brunning;
	bool m_bpaused;
	static Game* s_pInstance;
};

typedef Game TheGame;

#endif
