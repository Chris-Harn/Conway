#include "Board.h"

#include"Main.h"
#include "Tile.h"
#include "ChangeList.h"
#include "Graphics.h"
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>

Board* Board::s_pinstance = 0;

Board::Board() : m_tableWidth( 0 ), m_tableHeight( 0 ), m_ptable( 0 ), m_pflipList( 0 ) {

}

void Board::init( int width, int height ) {
	m_tableWidth = width;
	m_tableHeight = height;
	m_ptable = new Tile[ width * height ];
	m_pflipList = new ChangeList( width * height );

	// Hardcode Riley's Breeder using rule B3/S23
	int k, currentNumber;
	for( int num = 0; num < 3; num++ ) {
		// k creates three cascading Breeders
		k = ( num * m_tableWidth * 300 ) + ( num * 500 ); 
		currentNumber = ( 41 * m_tableWidth ) + 133 + k;
		m_ptable[ currentNumber + 1 ].setLive();	

		currentNumber = ( 42 * m_tableWidth ) + 134 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 43 * m_tableWidth ) + 130 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber += 1 + 3;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 44 * m_tableWidth ) + 131 + k;
		for( int i = 0; i < 4; i++ ) {
			m_ptable[ currentNumber + 1 + i ].setLive();
		}

		currentNumber = ( 47 * m_tableWidth ) + 130 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 48 * m_tableWidth ) + 131 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 49 * m_tableWidth ) + 132 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber = ( 50 * m_tableWidth ) + 132 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber = ( 51 * m_tableWidth ) + 131 + k;
		for( int i = 0; i < 2; i++ ) {
			m_ptable[ currentNumber + 1 + i ].setLive();
		}

		currentNumber = ( 55 * m_tableWidth ) + 133 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 56 * m_tableWidth ) + 134 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 57 * m_tableWidth ) + 130 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber += 1 + 3;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 58 * m_tableWidth ) + 131 + k;
		for( int i = 0; i < 4; i++ ) {
			m_ptable[ currentNumber + 1 + i ].setLive();
		}

		currentNumber = ( 67 * m_tableWidth ) + 96 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 68 * m_tableWidth ) + 97 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 69 * m_tableWidth ) + 93 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber += 1 + 3;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 70 * m_tableWidth ) + 94 + k;
		for( int i = 0; i < 4; i++ ) {
			m_ptable[ currentNumber + 1 + i ].setLive();
		}

		currentNumber = ( 78 * m_tableWidth ) + 3 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 79 * m_tableWidth ) + 4 + k;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 80 * m_tableWidth ) + 0 + k;
		m_ptable[ currentNumber + 1 ].setLive();
		currentNumber += 1 + 3;
		m_ptable[ currentNumber + 1 ].setLive();

		currentNumber = ( 81 * m_tableWidth ) + 1 + k;
		for( int i = 0; i < 4; i++ ) {
			m_ptable[ currentNumber + 1 + i ].setLive();
		}
	}
}

void Board::clean() {
	if( m_ptable != 0 ) {
		delete []m_ptable;
		m_ptable = 0;
	}
	if( m_pflipList != 0 ) {
		delete m_pflipList;
	}
}

void Board::clearScreen() {
	TheGraphics::instance()->clearSDLBoard();
}

void Board::drawScreen() {
	TheGraphics::instance()->drawSDLBoard();
}

void Board::drawEntireScreen() {
	int currentNumber;	
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			( m_ptable[ currentNumber ].alive() ) ? TheGraphics::instance()->drawAlive( i, j ) : TheGraphics::instance()->drawDead( i, j );
		}
	}
	TheGraphics::instance()->drawSDLBoard();
}

void Board::countNeighbors() {
	int currentNumber;
	int livingNeighbors;
	int i, j;
	for( j = 0; j < m_tableHeight; j++ ) {
		for( i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	

			// tally live tiles from eight neighbors
			livingNeighbors = 0;

			// left 
			if( i - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else 
				livingNeighbors += m_ptable[ currentNumber - 1 + m_tableWidth ].alive();

			// right 
			if( i + 1 < m_tableWidth )
				livingNeighbors += m_ptable[ currentNumber + 1 ].alive();
			else 
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();

			// top
			if( j - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth ].alive();
			else // if( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth + ( m_tableWidth * m_tableHeight ) ].alive();

			// bottom 
			if( j + 1 < m_tableHeight )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth ].alive();
			else
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth - ( m_tableWidth * m_tableHeight ) ].alive();
			
			// top left
			if( ( i - 1 >= 0 ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber - 1 - m_tableWidth ].alive();
			else if ( ( i == 0 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - 1 ].alive();
			else if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else if( j == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// top right
			if( ( i + 1  < m_tableWidth ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();
			else if( ( i == m_tableWidth - 1 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - m_tableWidth ].alive();
			else if ( i == m_tableWidth - 1 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 - ( m_tableWidth * 2 ) ].alive();
			else if ( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// bottom left 
			if( ( i - 1 >= 0 ) && ( j + 1 < m_tableHeight ) )
				livingNeighbors += m_ptable[ currentNumber - 1 + m_tableWidth ].alive();
			else if( ( i == 0 ) && ( j == m_tableHeight - 1 ) )
				livingNeighbors += m_ptable[ m_tableWidth - 1 ].alive();
			else if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + ( m_tableWidth * 2 ) ].alive();
			else if( j == m_tableHeight - 1 )
				livingNeighbors += m_ptable[ currentNumber - 1 - ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();
			
			// bottom right
			if( ( i + 1 < m_tableWidth ) && ( j + 1 < m_tableHeight ) )
				livingNeighbors += m_ptable[ currentNumber + 1 + m_tableWidth ].alive();
			else if( ( i == m_tableWidth - 1 ) && ( j == m_tableHeight - 1 ) )
				livingNeighbors += m_ptable[ 0 ].alive();
			else if( i == m_tableWidth - 1 )
				livingNeighbors += m_ptable[ currentNumber + 1 ].alive();
			else if( j == m_tableHeight - 1 )
				livingNeighbors += m_ptable[ currentNumber + 1 - ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// make current number have those numbers now
			m_ptable[ currentNumber ].setLive( livingNeighbors );

			// if tile changing is true, add to list to change later
			if( m_ptable[ currentNumber ].findIfChanging() == true ) {
				m_pflipList->addNumberToList( currentNumber );	
			}
		}
	}
}	
	

void Board::drawOnBoard( int x, int y ) {
	if( TheGame::instance()->gamePaused() == true ) {
		int currentNumber = x + ( y * m_tableWidth );	

		m_ptable[ currentNumber ].flip();	
		TheGraphics::instance()->updateSDLBoard( x, y, m_ptable[ currentNumber ].alive() ); 
	}
}

void Board::updateBoard() {
	int currentNumber = 0;
	int i = 0;
	int j = 0;

	while( m_pflipList->removeNumberFromList( currentNumber ) == true ) {
		if( currentNumber != 0 ) {
			i = currentNumber % m_tableWidth;	
			j = currentNumber / m_tableWidth;
		} else {
			i = 0;
			j = 0;
		}
		m_ptable[ currentNumber ].flip();

		TheGraphics::instance()->updateSDLBoard( i, j, m_ptable[ currentNumber ].alive() );
	}
}

int Board::getTableWidth() {
	return m_tableWidth;
}

int Board::getTableHeight() {
	return m_tableHeight;
}
