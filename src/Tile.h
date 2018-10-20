#ifndef __TILE__
#define __TILE__

enum Status {
	Dead,
	Alive
};

class Tile {
public:
	Tile( int setX, int setY );
	~Tile();

	Status getState();
private:
	int m_x;
	int m_y;
	Status m_currentStatus;

};

#endif
