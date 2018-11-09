#ifndef __GAME__
#define __GAME__

class Board;

/**************************************************
 *  Game
 *  Purpose: Abstracts simulation init, sim loop,
 *  and cleanup.
 *
 *************************************************/

class Game {
public:
	bool init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight );
	void render();
	void update();
	void handleEvents();
	void clean();
	
	bool running() { return m_brunning; }
	bool gamePaused();
	void pauseBoard();
	void unpauseBoard();
	void exit() { m_brunning = false; }
	static Game* instance() {
		if( s_pinstance == 0 ) {
			s_pinstance = new Game();
		}
		return s_pinstance;
	}

private:
	Game();
	bool m_brunning;
	bool m_bpaused;
	static Game* s_pinstance;
};

typedef Game TheGame;

#endif
