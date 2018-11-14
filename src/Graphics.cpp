#include "Graphics.h"

#include <SDL2/SDL.h>


Graphics* Graphics::s_pinstance = 0;


/**************************************************
 *  Graphics::Graphics
 *  Purpose: Constructor.  
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

Graphics::Graphics() : m_prenderer( 0 ), m_pwindow( 0 ) {

}


/**************************************************
 *  Graphics::init
 *  Purpose: Creates window context, clears board, 
 *  and flips the buffer for the first time.
 *  Input: Takes in int values for screen width and 
 *  screen height that correspond with pixel width
 *  and pixel height. Starts all the SDL subsystems.
 *  Return: Returns true if there is an error, false
 *  if there is none.
 *
 *************************************************/

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


/**************************************************
 *  Graphics::clean
 *  Purpose: Frees the window and the renderer. 
 *  Shuts down SDL systems started.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Graphics::clean() {	
	SDL_DestroyWindow( m_pwindow );
	SDL_DestroyRenderer( m_prenderer );
	m_pwindow = NULL;
	m_prenderer = NULL;
	SDL_Quit();
}


/**************************************************
 *  Graphics::drawSDLBoard
 *  Purpose: Flips buffer.
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Graphics::drawSDLBoard() {
	SDL_RenderPresent( m_prenderer );
}


/**************************************************
 *  Graphics::clearSDLBoard
 *  Purpose: Turns the buffer black, and flips it. 
 *  Input: None.
 *  Return: None.
 *
 *************************************************/

void Graphics::clearSDLBoard() {
	// use only once - will setup board to draw on initially
	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );
	SDL_RenderClear( m_prenderer );
	SDL_RenderPresent( m_prenderer );
}


/**************************************************
 *  Graphics::updateSDLBoard
 *  Purpose: Takes in 2d coordinates, and if the tile
 *  is alive, and draws it directly to the window.
 *  Input: Int for x and y coordinates, and a bool for
 *  statue of tile.
 *  Return: None.
 *
 *************************************************/

void Graphics::updateSDLBoard( int x, int y, bool alive ) {
	if( alive == true ) {
		drawAlive( x, y );
	} else {
		drawDead( x, y );
	}	
}


/**************************************************
 *  Graphics::drawAlive
 *  Purpose: Draws a 2d coordinate tile alive... 
 *  but doesn't flip the buffer. 
 *  Input: int for x and y coordinates.
 *  Return: None.
 *
 *************************************************/

void Graphics::drawAlive( int x, int y ) {
	SDL_SetRenderDrawColor( m_prenderer, 255, 255, 255, 255 );	
	SDL_Rect rectangle = { x * CELL_SIZE_X, y * CELL_SIZE_Y, CELL_SIZE_X, CELL_SIZE_Y };
	SDL_RenderFillRect( m_prenderer, &rectangle );
}


/**************************************************
 *  Graphics::drawDead
 *  Purpose: Draws a 2d coordinate tile dead...
 *  but doesn't flip the buffer. 
 *  Input: int for x and y coordinates.
 *  Return: None.
 *
 *************************************************/

void Graphics::drawDead( int x, int y ) {
	SDL_SetRenderDrawColor( m_prenderer, 0, 0, 0, 255 );	
	SDL_Rect rectangle = { x * CELL_SIZE_X, y * CELL_SIZE_Y, CELL_SIZE_X, CELL_SIZE_Y };
	SDL_RenderFillRect( m_prenderer, &rectangle );
}
