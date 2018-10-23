#ifndef __GAME__
#define __GAME__

class Board;

class Game {
public:
	void init( int boardWidth, int boardHeight );
	void render();
	void update();
	void handleEvents();
	void clean();
	
	~Game();
	bool running() { return m_bRunning; }
	void exit() { m_bRunning = false; }
	static Game* Instance() {
		if( s_pInstance == 0 ) {
			s_pInstance = new Game();
			return s_pInstance;	
		}
		return s_pInstance;
	}
private:
	Game();
	void changePause();
	bool gamePaused();
	Board *m_pboard;
	bool m_bRunning;
	bool m_bPaused;
	static Game* s_pInstance;
};

typedef Game TheGame;

#endif
