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
	m_pboard->clearScreen();
	m_pboard->drawBoard();
//	m_pboard->drawNumbers();
}

void Game::update() {
//	m_pboard->randomizeBoard();
	m_pboard->countNeighbors();
	m_pboard->updateBoard();
}

void Game::handleEvents() {

}

void Game::clean() {
	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
}
