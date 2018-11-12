#include "Tile.h"

#include "Main.h"


/**************************************************
 *  Tile::Tile
 *  Purpose: Constructor. Pauses tile to dead and 
 *  zero live neighbors.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Tile::Tile() : m_balive( 0 ), m_numberOfLiveNeighbors( 0 ) {

}


/**************************************************
 *  Tile::~Tile
 *  Purpose: Deconstructor
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Tile::~Tile() {

}


/**************************************************
 *  Tile::findIfChanging
 *  Purpose: Decides new state of the tile, compares
 *  it to old state, and returns true if states are
 *  different.
 *  Input: None.
 *  Return: bool (true) if the changing dead/alive
 *  status
 *
 *************************************************/

bool Tile::findIfChanging() {
	bool newStatus = m_balive;

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


/**************************************************
 *  Tile::flip
 *  Purpose: Changes the tile's state.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Tile::flip() {
	m_balive = !m_balive;
}


/**************************************************
 *  Tile::alive
 *  Purpose: Returns if the tile is alive or dead.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

int Tile::alive() {
	return m_balive;
}


/**************************************************
 *  Tile::setLive
 *  Purpose: Turns the tile living.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Tile::setLive() {
	m_balive = 1;
	m_numberOfLiveNeighbors = 3;
}


/**************************************************
 *  Tile::setLive
 *  Purpose: Takes an int and sets that to the number
 *  of living neighbors.
 *  Input: int that holds number of living neighbors.
 *  Return: None.
 *
 *************************************************/

void Tile::setLive( int liveNeighbors ) {
	m_numberOfLiveNeighbors = liveNeighbors;
}


/**************************************************
 *  Tile::numberAlive
 *  Purpose: Returns the number of neighbors alive
 *  known to the cell. 
 *  Input: None.
 *  Return: int value of living neighbor tiles.
 *
 *************************************************/

int Tile::numberAlive() {
	return m_numberOfLiveNeighbors;
}
