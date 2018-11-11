#include "Board.h"

#include"Main.h"
#include "Tile.h"
#include "ChangeList.h"
#include "Graphics.h"
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

Board* Board::s_pinstance = 0;

Board::Board() : m_tableWidth( 0 ), m_tableHeight( 0 ), m_ptable( 0 ), m_pflipList( 0 ) {

}

void Board::init( int width, int height ) {
	m_tableWidth = width;
	m_tableHeight = height;
	m_ptable = new Tile[ width * height ];
	m_pflipList = new ChangeList( width * height );


	int currentNumber;
	/*
	currentNumber = m_tableWidth / 2 + ( m_tableHeight / 2 * m_tableWidth );
			m_ptable[ currentNumber ].setLive();
			m_ptable[ currentNumber + 1].setLive();
			m_ptable[ currentNumber + 1 - m_tableWidth ].setLive();
			m_ptable[ currentNumber - 1 - m_tableWidth ].setLive();
			m_ptable[ currentNumber + m_tableWidth ].setLive();
	*/

	// create a series of gliders to test logic and performance
	currentNumber = 0;
	for( int i = 0; i < 240; i++ ) {
		currentNumber += i * m_tableWidth / 10;
		if( currentNumber < ( m_tableWidth * m_tableHeight - 10 ) ) {
			m_ptable[ currentNumber ].setLive();
			m_ptable[ currentNumber + 1].setLive();
			m_ptable[ currentNumber + 1 - m_tableWidth ].setLive();
			m_ptable[ currentNumber - 1 - m_tableWidth ].setLive();
			m_ptable[ currentNumber + m_tableWidth ].setLive();
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

			// left - correct
			if( i - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else //if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + m_tableWidth ].alive();

			// right - correct
			if( i + 1 < m_tableWidth )
				livingNeighbors += m_ptable[ currentNumber + 1 ].alive();
			else // if( i == m_tableWidth -1 )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();

			// top - correct	
			if( j - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth ].alive();
			else // if( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth + ( m_tableWidth * m_tableHeight ) ].alive();

			// bottom - correct
			if( j + 1 < m_tableHeight )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth ].alive();
			else// if( j == m_tableHeight - 1 )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth - ( m_tableWidth * m_tableHeight ) ].alive();
			
			// top left - appears correct
			if( ( i - 1 >= 0 ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber - 1 - m_tableWidth ].alive();
			else if ( ( i == 0 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - 1 ].alive();
			else if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else if( j == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// top right - appears correct
			if( ( i + 1  < m_tableWidth ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();
			else if( ( i == m_tableWidth - 1 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - m_tableWidth ].alive();
			else if ( i == m_tableWidth - 1 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 - ( m_tableWidth * 2 ) ].alive();
			else if ( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// bottom left - appears correct
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
	
void Board::countLivingTiles( int x, int y ) {
			int i = x;
			int j = y;
			int currentNumber = i + ( j * m_tableWidth );	

			// tally live tiles from eight neighbors
			int livingNeighbors = 0;

			// left - correct
			if( i - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else //if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + m_tableWidth ].alive();

			// right - correct
			if( i + 1 < m_tableWidth )
				livingNeighbors += m_ptable[ currentNumber + 1 ].alive();
			else // if( i == m_tableWidth -1 )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();

			// top - correct	
			if( j - 1 >= 0 )
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth ].alive();
			else // if( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber - m_tableWidth + ( m_tableWidth * m_tableHeight ) ].alive();

			// bottom - correct
			if( j + 1 < m_tableHeight )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth ].alive();
			else// if( j == m_tableHeight - 1 )
				livingNeighbors += m_ptable[ currentNumber + m_tableWidth - ( m_tableWidth * m_tableHeight ) ].alive();

			// top left - appears correct
			if( ( i - 1 >= 0 ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber - 1 - m_tableWidth ].alive();
			else if ( ( i == 0 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - 1 ].alive();
			else if( i == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 ].alive();
			else if( j == 0 )
				livingNeighbors += m_ptable[ currentNumber - 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// top right - appears correct
			if( ( i + 1  < m_tableWidth ) && ( j - 1 >= 0 ) )
				livingNeighbors += m_ptable[ currentNumber + 1 - m_tableWidth ].alive();
			else if( ( i == m_tableWidth - 1 ) && ( j == 0 ) ) 
				livingNeighbors += m_ptable[ ( m_tableWidth * m_tableHeight ) - m_tableWidth ].alive();
			else if ( i == m_tableWidth - 1 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 - ( m_tableWidth * 2 ) ].alive();
			else if ( j == 0 ) 
				livingNeighbors += m_ptable[ currentNumber + 1 + ( m_tableWidth * ( m_tableHeight - 1 ) ) ].alive();

			// bottom left - appears correct
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

			std::cout << "Found " << livingNeighbors << " around the cell at X: " << x << " Y: " << y << ".\n";
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
