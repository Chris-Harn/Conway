#include "Board.h"
#include "Tile.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Board::Board( int width, int height ) : m_tableWidth( width ), m_tableHeight( height ), m_pTable( 0 ) {
	m_pTable = new Tile[ width * height ];
	
	// create glider in middle to test logic
	int currentNumber = m_tableWidth/2 + ( (m_tableHeight / 2) * m_tableWidth );
	m_pTable[ currentNumber ].setLive( 3 ); // good
	m_pTable[ currentNumber + 1].setLive( 3 );
	m_pTable[ currentNumber + 1 - m_tableWidth ].setLive( 3 );
	m_pTable[ currentNumber - 1 - m_tableWidth ].setLive( 3 );
	m_pTable[ currentNumber + m_tableWidth ].setLive( 3 );
	updateBoard();
	
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

void Board::drawNumbers() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			m_pTable[ currentNumber ].drawNumber();
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
				m_pTable[ currentNumber ].setLive( 3 );
				m_pTable[ currentNumber ].flip();
			}
		}
	}
}

void Board::countNeighbors() {
	std::cout << "Inside count neighbor.\n";
	int currentNumber;
	int livingNeighbors;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			
			// tally live tiles from eight neighbors
			livingNeighbors = 0;
			// left
			if( i - 1 >= 0 )
				livingNeighbors += m_pTable[ currentNumber - 1 ].alive();
			
			// right
			if( i + 1 < m_tableWidth )
				livingNeighbors += m_pTable[ currentNumber + 1 ].alive();

			// top left
			if( ( i - 1 >= 0 ) && ( j -1 >= 0 ) ) 
				livingNeighbors += m_pTable[ currentNumber - 1 - m_tableWidth ].alive();

			// top	
			if( j - 1 >= 0 )
				livingNeighbors += m_pTable[ currentNumber - m_tableWidth ].alive();

			// top right
			if( ( j - 1 >= 0 ) && ( i + 1  < m_tableWidth ) )
				livingNeighbors += m_pTable[ currentNumber + 1 - m_tableWidth ].alive();

			// bottom left
			if( ( j + 1 < m_tableHeight ) && ( i - 1 >= 0 ) )
				livingNeighbors += m_pTable[ currentNumber - 1 + m_tableWidth ].alive();
			
			// bottom
			if( j + 1 < m_tableHeight )
				livingNeighbors += m_pTable[ currentNumber + m_tableWidth ].alive();

			// bottom right
			if( ( j + 1 < m_tableHeight ) && ( i + 1 < m_tableWidth ) )
				livingNeighbors += m_pTable[ currentNumber + 1 + m_tableWidth ].alive();

			if( livingNeighbors >= 3 ) 
					std::cout << "Setting a cell to live.\n";
			// make current number have those numbers now
			m_pTable[ currentNumber ].setLive( livingNeighbors );
		}
	}
}

void Board::updateBoard() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			m_pTable[ currentNumber ].flip();
		}
	}
}
