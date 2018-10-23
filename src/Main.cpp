#include <SDL2/SDL.h>
#include <iostream>

#include "Main.h"
#include "Game.h"
#include "Timer.h"

int main( int argc, char* argv[] ) {
	Timer Clock;
	Clock.init( DELAY_RENDERER, DELAY_UPDATE_BOARD );

	TheGame::Instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_HEIGHT, SCREEN_WIDTH );
	while( TheGame::Instance()->running() ) {
		TheGame::Instance()->handleEvents();

		if( Clock.timeForRender() ) {
			if( !TheGame::Instance()->gamePaused() && Clock.timeForUpdatingBoard() ) {
				TheGame::Instance()->update();
			}

			TheGame::Instance()->render();
		}
	}	
	TheGame::Instance()->clean();

	std::cout << "Program finished without issue." << std::endl;

	return 0;
}
