#ifndef __TILE__
#define __TILE__

class Tile {
public:
	Tile();
	~Tile();

	int alive();
	void draw();
	int numberAlive();
	void flip();
	void setLive( int liveNeighbors );
private:
	bool m_balive; 
	int numberOfLiveNeighbors;
};

#endif
