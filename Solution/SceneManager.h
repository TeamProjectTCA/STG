#pragma once
#include "Base.h"
#include <string>

PTR( SceneManager );

class SceneManager : public Base {
public:
	static SceneManagerPtr getTask( );
	static std::string getTag( );

public:
	SceneManager( );
	virtual ~SceneManager( );

public:
	void initialize( );
	void finalize( );
	void update( );
};

