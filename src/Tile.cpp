#include "Tile.h"

#include <iostream>

Tile::Tile() {
	int m_x = 0;
	int m_y = 0;
	m_balive = false;
	numberOfLiveNeighbors = 0;
}

Tile::~Tile() {

}

void Tile::setX( int x ) {
	m_x = x;
}

void Tile::setY( int y ) {
	m_y = y;
}

void Tile::draw() {
	if( m_balive ) {
		std::cout << "X";
	} else {
		std::cout << "O";
	}
}

void Tile::flip() {
	if ( numberOfLiveNeighbors < 2 ) {
		m_balive = false;
	} else if ( numberOfLiveNeighbors == 3 ) {
		m_balive = true;
	} else if ( numberOfLiveNeighbors < 4 ) {
		// do nothing
	} else if ( numberOfLiveNeighbors > 3 ) {
		m_balive = false;
	}

	numberOfLiveNeighbors = 0;
}

int Tile::alive() {
	return m_balive;
}

void Tile::setLive( int liveNeighbors ) {
	numberOfLiveNeighbors = liveNeighbors;
}
