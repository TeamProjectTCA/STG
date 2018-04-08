#include "SceneGame.h"
#include "Keyboard.h"
#include "Player.h"

SceneGame::SceneGame( ) {
	_keyboard = Keyboard::getTask( );
	_player = PlayerPtr( new Player( ) );
}

SceneGame::~SceneGame( ) {
}

void SceneGame::update( ) {
	_player->update( );
	_player->draw( );

	if ( _keyboard->getKeyDown( "z" ) ) {
		setNextScene( TITLE );
	}
}
