#include "Main.h"
#include "Game.h"
#include "Timer.h"

#include <iostream>

int main() {
	if( TheGame::instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT ) ) {
		return 1;
	}

	std::cout << "Finished initalizing game, graphics, board and input.\n";
	
	Timer Clock;
	Clock.init( DELAY_RENDERER, DELAY_UPDATE_BOARD );

	while( TheGame::instance()->running() ) {
		TheGame::instance()->handleEvents();

		if( Clock.timeForRender() ) {
			if( !TheGame::instance()->gamePaused() && Clock.timeForUpdatingBoard() ) {
				TheGame::instance()->update();
			}

			TheGame::instance()->render();
		}
	}	
	std::cout << "Successfully exited the game. Now Deleting memory allocated.\n";
	TheGame::instance()->clean();
	std::cout << "Finished clearing memory. Exiting program.\n";

	return 0;
}
