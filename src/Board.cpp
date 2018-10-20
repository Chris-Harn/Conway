#include "Board.h"

#include "Tile.h"

#include <iostream>

Board::Board( int width, int height ) : m_tableWidth( width ), m_tableHeight( height ), m_pTable( 0 ) {
	m_pTable = new Tile[ width * height ];
	
	int currentNumber;	
	for( int j = 0; j < m_tableHeight; j++ ) {
			for( int i = 0; i < m_tableWidth; i++ ) {
				currentNumber = i + ( j * m_tableWidth );
				m_pTable[ currentNumber ].setX( i + 1 );
				m_pTable[ currentNumber ].setY( j + 1 );
			}
		}
}

Board::~Board() {
	if( m_pTable != 0 ) {
		for( int j = 0; j < m_tableHeight; j++ ) {
			for( int i = 0; i < m_tableWidth; i++ ) {
				// std::cout << " " << i + ( j * m_tableWidth );
				//delete *m_pTable[ i + ( j * m_tableWidth ) ];
				// m_pTable[ i + ( j * m_tableWidth ) ] = 0;
			}
		}
	}
}
