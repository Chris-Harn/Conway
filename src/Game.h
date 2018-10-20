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
private:
	bool m_bRunning;
	Board *m_pboard;
};

#endif
