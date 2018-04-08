#include "Manager.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneManager.h"

void main( ) {
	ManagerPtr manager = Manager::getInstance( );

	DrawerPtr drawer( new Drawer( "Resources/image" ) );
	KeyboardPtr keyboard( new Keyboard( ) );
	MousePtr mouse( new Mouse( ) );
	SceneManagerPtr scene( new SceneManager( ) );

	//add
	manager->add( Drawer::getTag( ), drawer );
	manager->add( Keyboard::getTag( ), keyboard );
	manager->add( Mouse::getTag( ), mouse );
	manager->add( SceneManager::getTag( ), scene );
}