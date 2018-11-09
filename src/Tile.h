#ifndef __TILE__
#define __TILE__

/**************************************************
 *  Tile
 *  Purpose: Data and needed functions to manipulate
 *  tile data.
 *
 *************************************************/

class Tile {
public:
	Tile();
	~Tile();

	int alive();
	int numberAlive();
	bool findIfChanging();
	void flip();
	void setLive();
	void setLive( int liveNeighbors );
private:
	bool m_balive; 
	int m_numberOfLiveNeighbors;
};

#endif
