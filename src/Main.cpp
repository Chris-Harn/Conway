#include <SDL2/SDL.h>
#include <iostream>

#include "Main.h"
#include "Game.h"
#include "Timer.h"

int main( int argc, char* argv[] ) {
	Uint32 Timer = SDL_GetTicks();

	TheGame::Instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_HEIGHT, SCREEN_WIDTH );
	while( TheGame::Instance()->running() ) {
		TheGame::Instance()->handleEvents();

		if( ( SDL_GetTicks() - Timer ) > DELAY ) {
			Timer = SDL_GetTicks();
			if( !TheGame::Instance()->gamePaused() ) {
				TheGame::Instance()->update();
			}

			TheGame::Instance()->render();
		}
	}	
	TheGame::Instance()->clean();

	std::cout << "Program finished without issue." << std::endl;

	return 0;
}
