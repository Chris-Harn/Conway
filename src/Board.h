#ifndef __BOARD__
#define __BOARD__

class Tile;

class Board {
public:
	Board( int width, int height );
	~Board();	
private:
	int m_tableWidth;
	int m_tableHeight;
	Tile *m_pTable;
};

#endif
