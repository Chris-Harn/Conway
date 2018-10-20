#include "Board.h"

#include "Tile.h"

Board::Board( int width, int height ) : m_tableWidth( width ), m_tableHeight( height ), m_pTable( 0 ) {

}

Board::~Board() {
	if( m_pTable != 0 ) {
		delete m_pTable;
		m_pTable = 0;
	}
}
