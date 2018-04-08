#pragma once
#include "smart_ptr.h"

PTR( Character );

class Character {
public:
	Character( );
	virtual ~Character( );

public:
	virtual void update( ) = 0;
	virtual void draw( ) = 0;
};

