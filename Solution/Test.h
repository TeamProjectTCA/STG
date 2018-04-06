#pragma once
#include "smart_ptr.h"

PTR( Test );

class Test {
public:
	Test( );
	virtual ~Test( );

public:
	void update( );
};

