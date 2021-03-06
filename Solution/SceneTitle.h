#pragma once
#include "Scene.h"
#include "smart_ptr.h"
#include <string>

PTR( SceneTitle );
PTR( Drawer );
PTR( Keyboard );

class SceneTitle : public Scene {
public:
	SceneTitle( );
	virtual ~SceneTitle( );

public:
	void update( );

private:
	//変数
	int _background_handle;

	//クラス
	DrawerPtr _drawer;
	KeyboardPtr _keyboard;
};

