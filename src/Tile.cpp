#include "Tile.h"

#include <iostream>

Tile::Tile() {
	m_balive = false;
	numberOfLiveNeighbors = 0;
}

Tile::~Tile() {

}

void Tile::draw() {
	if( m_balive ) {
		std::cout << "X";
	} else {
		std::cout << "-";
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

void Tile::drawNumber() {
	std::cout << numberOfLiveNeighbors;
}
