#include "Tile.h"

#include <iostream>

Tile::Tile() {
	int m_x = 0;
	int m_y = 0;
	m_currentStatus = Status::Dead;
	numberOfLiveNeighbors = 0;
}

Tile::~Tile() {

}

Status Tile::getState() {
	return m_currentStatus;
}

void Tile::setX( int x ) {
	m_x = x;
}

void Tile::setY( int y ) {
	m_y = y;
}

void Tile::draw() {
	switch( m_currentStatus ) {
		case Status::Dead:
			std::cout << "O";
			break;
		case Status::Alive:
			std::cout << "X";
			break;
		default:
			std::cout << "E";
	}
}

void Tile::flip() {
		// remove at a later time
		if( m_currentStatus == Status::Dead ) {
			m_currentStatus = Status::Alive;
		} else {
			m_currentStatus = Status::Dead;
		}
	/*
	if ( numberOfLiveNeighbors < 2 ) {
		m_currentStatus == Status::Dead;
	} else if ( numberOfLiveNeighbors < 4 ) {
		// do nothing...
		return
	} else if ( numberOfLiveNeighbors > 3 ) {
		m_currentStatus == Status::Dead;
	} else if ( numberOfLiveNeighbors == 3 ) {
		m_currentStatus == Status::Alive;
	}
	*/
}
