/***********************************************************************
 * Source File:
 *    Ship
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Creates and handles the ship
 ************************************************************************/

#include "ship.h"

/***********************************************************************
 * return ship's angle
 ************************************************************************/
float Ship :: getAngle()
{
	return _angle;
}

/***********************************************************************
 * Move ship when thrust is applied
 ************************************************************************/
void Ship :: moveForward()
{
	_velocity.setDx(-sin((2 * M_PI * _angle)/360) * _thrust);
	_velocity.setDy(cos((2 * M_PI * _angle)/360) * _thrust);
	_center.addX(_velocity.getDx());
	_center.addY(_velocity.getDy());
}

/***********************************************************************
 * rotate ship when left arrow pressed
 ************************************************************************/
void Ship :: rotateLeft()
{
	_angle += ROTATE_AMOUNT;
}

/***********************************************************************
 * rotate ship when right arrow pressed
 ************************************************************************/
void Ship :: rotateRight()
{
	_angle -= ROTATE_AMOUNT;
}

/***********************************************************************
 * draw the ship
 ************************************************************************/
void Ship :: draw()
{
	drawShip(getCenter(), _angle, thrustOn);
}

/***********************************************************************
 * bool to determine when thrust is applied and flame should be drawn
 ************************************************************************/
void Ship :: setThrust(bool a)
{
	thrustOn = a;
}

/***********************************************************************
 * Resets the ship to center of screen when life is lost
 ************************************************************************/
void Ship :: resetShip()
{
	_velocity.setDx(0);
	_velocity.setDy(0);
	_center.setX(0);
	_center.setY(0);
	_angle = 0;
	_alive = true;
}
