#ifndef __TILE__
#define __TILE__

enum Status {
	Dead,
	Alive
};

class Tile {
public:
	int X;
	int Y;
	Status Current;

	Tile();
	~Tile();
};

#endif
