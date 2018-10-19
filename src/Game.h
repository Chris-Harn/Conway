#ifndef __GAME__
#define __GAME__

class Game {
public:
	void init();
	void render();
	void update()
	void handleEvents()
	void clean();
	
	Game();
	~Game();
private:
	bool m_bRunning;
};

#endif
