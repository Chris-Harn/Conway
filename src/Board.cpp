#include "Board.h"
#include "Tile.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

	// test randomize factor
	srand( time( NULL ) );
}

Board::~Board() {
	if( m_pTable != 0 ) {
		delete []m_pTable;
		m_pTable = 0;
	}
}

void Board::clearScreen() {
	// console version- doesn't matter
	//std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::cout << "\x1B[2J\x1B[H";
}

void Board::drawBoard() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			m_pTable[ currentNumber ].draw();
		}
		std::cout << "\n";
	}
}

void Board::randomizeBoard() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			if( ( rand() % 3 + 1 ) == 3 ) {
				m_pTable[ currentNumber ].flip();
			}
		}
	}

}
