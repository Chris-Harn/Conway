#include "Game.h"

#include "Board.h"
#include "Input.h"

#include <cstddef>

Game* Game::s_pInstance = 0;

Game::Game() : m_pboard( 0 ), m_brunning( true ), m_bpaused( true ) {
	
}

Game::~Game() {

}

bool Game::init( const int boardWidth, const int boardHeight, const int screenWidth, const int screenHeight ) {
	if( SDL_Init( SDL_INIT_EVERYTHING ) >= 0 ) {
		m_pwindow = SDL_CreateWindow( "Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );	

		if( m_pwindow != 0 ) {
			m_prenderer = SDL_CreateRenderer( m_pwindow, -1, 0 );	
		}
	} else {
		return 1;
	}

	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );
	SDL_RenderClear( m_prenderer );
	SDL_RenderPresent( m_prenderer );

	m_pboard = new Board( boardWidth, boardHeight );

	return 0;
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
	TheInputHandler::Instance()->update();
	if( TheInputHandler::Instance()->onKeyDown( SDL_SCANCODE_SPACE ) ) {
		TheGame::Instance()->changePause();
	}
}

void Game::clean() {
	SDL_DestroyWindow( m_pwindow );
	SDL_DestroyRenderer( m_prenderer );
	SDL_Quit();

	if( m_pboard != 0 ) {
		delete m_pboard;
		m_pboard = NULL;
	}
}

void Game::changePause() { 
	m_bpaused = !m_bpaused;
}

bool Game::gamePaused() {
	return m_bpaused;
}
