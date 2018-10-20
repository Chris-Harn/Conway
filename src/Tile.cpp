#include "Tile.h"

Tile::Tile( int setX, int setY ) {
	int m_x = setX;
	int m_y = setY;
	m_currentStatus = Status::Dead;
}

Tile::~Tile() {

}

Status Tile::getState() {
	return m_currentStatus;
}
