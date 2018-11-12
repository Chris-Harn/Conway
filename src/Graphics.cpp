#include "Graphics.h"

#include <SDL2/SDL.h>


Graphics* Graphics::s_pinstance = 0;

Graphics::Graphics() : m_prenderer( 0 ), m_pwindow( 0 ) {

}

bool Graphics::init( const int screenWidth, const int screenHeight ) {
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) >= 0 ) {
		m_pwindow = SDL_CreateWindow( "Conway's Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_FULLSCREEN );

		if( m_pwindow != 0 ) {
			m_prenderer = SDL_CreateRenderer( m_pwindow, -1, 0 );
		} else {
			SDL_LogError( SDL_LOG_CATEGORY_APPLICATION,
					"Initialize_display - SDL_CreateWindowAndRenderer: %s\n",
					SDL_GetError() );
			return true;

		}
	} else {
		SDL_LogError( SDL_LOG_CATEGORY_APPLICATION,
				"Initialize_display - SDL_Init: %s\n",
				SDL_GetError() );
		return true;
	}

	clearSDLBoard();
	drawSDLBoard();

	return false;
}

void Graphics::clean() {	
	SDL_DestroyWindow( m_pwindow );
	SDL_DestroyRenderer( m_prenderer );
	m_pwindow = NULL;
	m_prenderer = NULL;
	SDL_Quit();
}

void Graphics::drawSDLBoard() {
	SDL_RenderPresent( m_prenderer );
}

void Graphics::clearSDLBoard() {
	// use only once - will setup board to draw on initially
	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );
	SDL_RenderClear( m_prenderer );
	SDL_RenderPresent( m_prenderer );
}

void Graphics::updateSDLBoard( int x, int y, bool alive ) {
	if( alive == true ) {
		drawAlive( x, y );
	} else {
		drawDead( x, y );
	}	
}

void Graphics::drawAlive( int x, int y ) {
	SDL_SetRenderDrawColor( m_prenderer, 255, 255, 255, 255 );	
	SDL_Rect rectangle = { x * CELL_SIZE_X, y * CELL_SIZE_Y, CELL_SIZE_X, CELL_SIZE_Y };
	SDL_RenderFillRect( m_prenderer, &rectangle );
}

void Graphics::drawDead( int x, int y ) {
	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );	
	SDL_Rect rectangle = { x * CELL_SIZE_X, y * CELL_SIZE_Y, CELL_SIZE_X, CELL_SIZE_Y };
	SDL_RenderFillRect( m_prenderer, &rectangle );
}
