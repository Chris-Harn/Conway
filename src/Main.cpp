#include "Main.h"
#include "Game.h"
#include "Timer.h"

int main() {
	Timer Clock;
	Clock.init( DELAY_RENDERER, DELAY_UPDATE_BOARD );

	TheGame::Instance()->init( GAME_WIDTH, GAME_HEIGHT, SCREEN_WIDTH, SCREEN_HEIGHT );
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

	return 0;
}
