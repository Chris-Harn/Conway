#include "Game.h"

#include "Board.h"
#include "Input.h"

Game* Game::s_pInstance = 0;

Game::Game() : m_pboard( 0 ), m_brunning( true ), m_bpaused( true ) {
	
}

Game::~Game() {

}

bool Game::init( const int boardWidth, const int boardHeight ) {
	m_pboard = new Board( boardWidth, boardHeight );

	return 0;
}

void Game::render() {
	m_pboard->clearScreen();
	m_pboard->drawBoard();
//	m_pboard->drawNumbers(); // shows neighbor cell counts
}

void Game::update() {
//	m_pboard->randomizeBoard(); // generates random cells to test performance
	m_pboard->countNeighbors();
	m_pboard->updateBoard();
}

void Game::handleEvents() {
	TheInputHandler::Instance()->update();
	if( TheInputHandler::Instance()->onKeyDown( SDL_SCANCODE_SPACE ) ) {
		TheGame::Instance()->unpauseBoard();
	}

	if( TheInputHandler::Instance()->onKeyDown( SDL_SCANCODE_RETURN ) ) {
		TheGame::Instance()->pauseBoard();
	}
}

void Game::clean() {
	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
}

void Game::pauseBoard() {
	m_bpaused = true;
}

void Game::unpauseBoard() {
	m_bpaused = false;
}

bool Game::gamePaused() {
	return m_bpaused;
}
