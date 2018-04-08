#pragma once
#include "smart_ptr.h"
#include "Character.h"

PTR( Player );
PTR( Drawer );

class Player : public Character {
public:
	Player( );
	virtual ~Player( );

public:
	void update( );
	void draw( );

private:
	DrawerPtr _drawer;
};

