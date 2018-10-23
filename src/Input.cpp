#include "Input.h"

#include "Game.h"


Input* Input::s_pInstance = 0;

Input::Input() {
	for( int i = 0; i < 3; i++ ) {
		m_mouseButtonStates.push_back( false );
	}

	m_keystates = SDL_GetKeyboardState(0);
}

Input::~Input() {

}

void Input::update() {
	SDL_Event event;
	while( SDL_PollEvent( &event ) ) {
		if( event.type == SDL_QUIT ) {
			TheGame::Instance()->exit();
		}

		if( event.type == SDL_MOUSEBUTTONDOWN ) {
			if( event.button.button = SDL_BUTTON_LEFT ) {
				m_mouseButtonStates[LEFT] = true;
			}
		}

		if( event.type == SDL_MOUSEBUTTONUP ) {
			if( event.button.button = SDL_BUTTON_LEFT ) {
				m_mouseButtonStates[LEFT] = false;
			}
		}
	}
}

void Input::clean() {

}

void Input::onKeyDown() {

}

bool Input::onKeyDown( SDL_Scancode key ) {
	if( m_keystates != 0 ) {
		if( m_keystates[key] == 1 ) {
			return true;
		} else {
			return false;	
		}
	}	
	return false;
}

void Input::onKeyUp() {

}

void Input::onMouseMove( SDL_Event& event ) {

}

void Input::onMouseButtonDown( SDL_Event& event ) {

}

void Input::onMouseButtonUp( SDL_Event& event ) {

}
