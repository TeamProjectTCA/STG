#include "Test.h"
#include "SceneTitle.h"
#include "Keyboard.h"

Test::Test( ) {
}

Test::~Test( ) {
}

void Test::update( ) {
	KeyboardPtr key = Keyboard::getTask( );
	if ( key->getState( "a" ) ) {
		int a = 0;
	}

	std::string str = key->getString( );

	if ( str == "a" ) {
		int a = 0;
	}

	if ( key->getKeyUp( "a" ) ) {
		int a = 0;
	}
}