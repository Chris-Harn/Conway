#ifndef __TILE__
#define __TILE__

class Tile {
public:
	Tile();
	Tile( int x, int y );
	~Tile();

	int alive();
	void setX( int x );
	void setY( int y );
	void draw();
	void drawNumber();
	void flip();
	void setLive( int liveNeighbors );
private:
	int m_x;
	int m_y;
	bool m_balive; 
	int numberOfLiveNeighbors;
};

#endif
