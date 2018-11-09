#include "Board.h"

#include "Tile.h"
#include "ChangeList.h"
#include "Graphics.h"

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
	
	// create glider in middle to test logic
	int currentNumber = m_tableWidth/2 + ( (m_tableHeight / 2) * m_tableWidth );
	m_ptable[ currentNumber ].setLive();
	m_ptable[ currentNumber + 1].setLive();
	m_ptable[ currentNumber + 1 - m_tableWidth ].setLive();
	m_ptable[ currentNumber - 1 - m_tableWidth ].setLive();
	m_ptable[ currentNumber + m_tableWidth ].setLive();
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
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			m_ptable[ currentNumber ].setLive( 0 );
			
			// tally live tiles from eight neighbors
			livingNeighbors = 0;
			// left
			if( i - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			
			// right
			if( i + 1 < m_tableWidth )
				livingNeighbors += m_ptable[ currentNumber + 1 ].alive();

			// top left
			if( ( i - 1 >= 0 ) && ( j -1 >= 0 ) ) 
				livingNeighbors += m_ptable[ currentNumber - 1 - m_tableWidth ].alive();

			// top	
			if( j - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth ].alive();

			// top right
			if( ( j - 1 >= 0 ) && ( i + 1  < m_tableWidth ) )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();

			// bottom left
			if( ( j + 1 < m_tableHeight ) && ( i - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber - 1 + m_tableWidth ].alive();
			
			// bottom
			if( j + 1 < m_tableHeight )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth ].alive();

			// bottom right
			if( ( j + 1 < m_tableHeight ) && ( i + 1 < m_tableWidth ) )
				livingNeighbors += m_ptable[ currentNumber + 1 + m_tableWidth ].alive();

			// make current number have those numbers now
			m_ptable[ currentNumber ].setLive( livingNeighbors );


			// if tile changing is true, add to list to change later
			if( m_ptable[ currentNumber ].findIfChanging() == true ) {
				m_pflipList->addNumberToList( currentNumber );	
			}
		}
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
