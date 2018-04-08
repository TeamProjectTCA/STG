#include "Player.h"
#include "Drawer.h"
#include "Vector.h"

Player::Player( ) {
	_drawer = Drawer::getTask( );
}

Player::~Player( ) {
}

void Player::update( ) {
}

void Player::draw( ) {
	Vector vec;
	_drawer->drawShere( vec, 100, 50, 0xff0000, 0xff0000, false );
}