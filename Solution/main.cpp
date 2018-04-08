#include <vector>
#include <string>
#include "DxLib.h"
#include "Manager.h"
#include "const.h"
#include "LoadCSV.h"
#include "Drawer.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "SceneManager.h"

void setScreenSize( int *width, int *height ) {
	*width = SCREEN_WIDTH;
	*height = SCREEN_HEIGHT;

	LoadCSVPtr load( new LoadCSV( ) );
	std::vector< CsvData > data;
	load->read( data, "screen" );

	int size = ( int )data.size( );
	for ( int i = 0; i < size; i++ ) {
		if ( "CLIENT_WIDTH" == data[ i ].tag ) {
			*width = atoi( data[ i ].values.begin( )->c_str( ) );
			continue;
		}

		if ( "CLIENT_HEIGHT" == data[ i ].tag ) {
			*height = atoi( data[ i ].values.begin( )->c_str( ) );
			continue;
		}
	}
}

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow ) {
	SetWindowText( "Mirror" );
	ChangeWindowMode( TRUE );

	//スクリーンサイズを詰める
	int screen_width = 0;
	int screen_height = 0;
	setScreenSize( &screen_width, &screen_height );

	SetWindowSize( screen_width, screen_height );
	SetGraphMode( WIDTH, HEIGHT, 32 );
	SetDoubleStartValidFlag( TRUE );
	SetAlwaysRunFlag( TRUE );
	if ( DxLib_Init( ) != 0 ) {
		return -1;
	}
	SetDrawScreen( DX_SCREEN_BACK );

	{
		Manager::initialize( );
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

		//addしたクラスの初期化
		manager->allInitialize( );

		while ( true ) {
			if ( ScreenFlip( ) != 0 || ProcessMessage( ) != 0 || ClearDrawScreen( ) != 0 ) {
				break;
			}

			manager->update( );

			if ( CheckHitKey( KEY_INPUT_ESCAPE ) ) {
				break;
			}
		}

		Manager::finalize( );
	}

	DxLib_End( );
	return 0;
}