#ifndef __TILE__
#define __TILE__

enum Status {
	Dead,
	Alive
};

class Tile {
public:
	int m_x;
	int m_y;
	Status m_currentStatus;

	Tile();
	~Tile();
};

#endif
