#ifndef __TILE__
#define __TILE__

enum Status {
	Dead,
	Alive
};

class Tile {
public:
	Tile();
	Tile( int x, int y );
	~Tile();

	Status getState();
	void setX( int x );
	void setY( int y );
	void draw();
	void flip();
private:
	int m_x;
	int m_y;
	Status m_currentStatus;
};

#endif
