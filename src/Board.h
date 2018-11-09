#ifndef __BOARD__
#define __BOARD__

class Tile;
class ChangeList;

/**************************************************
 *  Board
 *  Purpose: Allocates and manipulates board. Also
 *  commands what to draw.
 *
 *************************************************/

class Board {
public:
	void init( int width, int height );
	void clean();

	void clearScreen();
	void drawScreen();
	void drawEntireScreen();
	void countNeighbors();
	void updateBoard();
	void drawOnBoard( int x, int y );

	int getTableWidth();
	int getTableHeight();

	static Board* instance() {
		if( s_pinstance == 0 ) {
			s_pinstance = new Board();
		}
		return s_pinstance;
	}
private:
	Board();
	int m_tableWidth;
	int m_tableHeight;
	Tile *m_ptable;
	ChangeList *m_pflipList;
	static Board *s_pinstance;
};

typedef Board TheBoard;

#endif
