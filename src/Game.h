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
	
	Game();
	~Game();
	bool running() { return m_bRunning; }
	void exit() { m_bRunning = false; }
private:
	Board *m_pboard;
	bool m_bRunning;
};

#endif
