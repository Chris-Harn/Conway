#include "Tile.h"

Tile::Tile() {
	int m_x = 0;
	int m_y = 0;
	m_currentStatus = Status::Dead;
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
