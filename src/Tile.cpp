#include "Tile.h"

#include "Graphics.h"

Tile::Tile() : m_balive( 0 ), numberOfLiveNeighbors( 0 ) {

}

Tile::~Tile() {

}

void Tile::draw() {
	( m_balive ) ? TheGraphics::instance()->drawX() : TheGraphics::instance()->drawEmpty();
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

int Tile::numberAlive() {
	return numberOfLiveNeighbors;
}
