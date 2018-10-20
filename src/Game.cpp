#include "Game.h"

#include "Board.h"

#include <cstddef>

Game::Game() : m_bRunning( true ), m_pboard( 0 ) {

}

Game::~Game() {

}

void Game::init( int boardWidth, int boardHeight ) {
	m_pboard = new Board( boardWidth, boardHeight );
}

void Game::render() {

}

void Game::update() {

}

void Game::handleEvents() {

}

void Game::clean() {
	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
}
