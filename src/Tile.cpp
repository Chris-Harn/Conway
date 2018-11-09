#include "Tile.h"

#include "Main.h"

Tile::Tile() : m_balive( 0 ), m_numberOfLiveNeighbors( 0 ) {

}

Tile::~Tile() {

}

bool Tile::findIfChanging() {
	bool newStatus = m_balive;

	/*
	if ( m_numberOfLiveNeighbors < 2 ) {
		newStatus = false;
	} else if ( m_numberOfLiveNeighbors == 3 ) {
		newStatus = true;
	} else if ( m_numberOfLiveNeighbors < 4 ) {
		// do nothing
	} else if ( m_numberOfLiveNeighbors > 3 ) {
		newStatus = false;
	}
	*/

	if( m_numberOfLiveNeighbors == REPRODUCE_NUMBER ) {
		newStatus = true;
	} else if( m_numberOfLiveNeighbors > OVERPOPULATION_NUMBER || m_numberOfLiveNeighbors < ISOLATION_NUMBER ) {
		newStatus = false;
	}

	if( newStatus != m_balive ) {
		return true;
	}

	return false;
}

void Tile::flip() {
	m_balive = !m_balive;
}

int Tile::alive() {
	return m_balive;
}

void Tile::setLive() {
	m_balive = 1;
	m_numberOfLiveNeighbors = 3;
}

void Tile::setLive( int liveNeighbors ) {
	m_numberOfLiveNeighbors = liveNeighbors;
}

int Tile::numberAlive() {
	return m_numberOfLiveNeighbors;
}
