#ifndef __BOARD__
#define __BOARD__

class Tile;

class Board {
public:
	Board( int width, int height );
	~Board();

	void clearScreen();
	void drawBoard();
	void drawNumbers();
	void countNeighbors();
	void updateBoard();
	void randomizeBoard();
private:
	int m_tableWidth;
	int m_tableHeight;
	Tile *m_pTable;
};

#endif
