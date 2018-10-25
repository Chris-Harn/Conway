#include "Board.h"

#include "Tile.h"
#include "Graphics.h"

#include <stdio.h>
#include <stdlib.h>

Board* Board::s_pinstance = 0;

Board::Board() : m_tableWidth( 0 ), m_tableHeight( 0 ), m_ptable( 0 ) {

}

void Board::init( int width, int height ) {
	m_tableWidth = width;
	m_tableHeight = height;
	m_ptable = new Tile[ width * height ];
	
	// create glider in middle to test logic
	int currentNumber = m_tableWidth/2 + ( (m_tableHeight / 2) * m_tableWidth );
	m_ptable[ currentNumber ].setLive( 3 ); // good
	m_ptable[ currentNumber + 1].setLive( 3 );
	m_ptable[ currentNumber + 1 - m_tableWidth ].setLive( 3 );
	m_ptable[ currentNumber - 1 - m_tableWidth ].setLive( 3 );
	m_ptable[ currentNumber + m_tableWidth ].setLive( 3 );
	updateBoard(); 
}

void Board::clean() {
	if( m_ptable != 0 ) {
		delete []m_ptable;
		m_ptable = 0;
	}
}

void Board::clearScreen() {
	TheGraphics::instance()->clearScreen();
}

void Board::drawBoard() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			( m_ptable[ currentNumber ].alive() ) ? TheGraphics::instance()->drawX() : TheGraphics::instance()->drawEmpty();
		}
		TheGraphics::instance()->nextLine();
	}
}

void Board::drawNumbers() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			TheGraphics::instance()->drawInt( m_ptable[ currentNumber].numberAlive() );
			//m_ptable[ currentNumber ].drawNumber();
		}
		TheGraphics::instance()->nextLine();
	}
}

void Board::countNeighbors() {
	int currentNumber;
	int livingNeighbors;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			
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
		}
	}
}

void Board::updateBoard() {
	int currentNumber;
	for( int j = 0; j < m_tableHeight; j++ ) {
		for( int i = 0; i < m_tableWidth; i++ ) {
			currentNumber = i + ( j * m_tableWidth );	
			m_ptable[ currentNumber ].flip();
		}
	}
}

int Board::getTableWidth() {
	return m_tableWidth;
}

int Board::getTableHeight() {
	return m_tableHeight;
}
