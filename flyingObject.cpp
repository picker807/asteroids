/***********************************************************************
 * Source File:
 *    	Flying Object
 * Author:
 *    	Aaron Picker
 * Summary:
 *   	Base class for all objects that move in the game
 ************************************************************************/

#include "flyingObject.h"

/**********************************************************************
 * Flying Object Constructor
 *************************************************************************/
FlyingObject::FlyingObject()
{
	_alive = true;
	_angle = 0;
}

/**********************************************************************
 * Checks if the object is alive
 *************************************************************************/
bool FlyingObject :: isAlive()
{
	if (_alive)
		return true;
	else
		return false;
}

/**********************************************************************
 * Moves the object
 *************************************************************************/
void FlyingObject::advance()
{
	_center.addX(_velocity.getDx());
	_center.addY(_velocity.getDy());
    int range = 600;
	float x = _center.getX();
	float y = _center.getY();
	
	if (x > range)
		_center.setX(-range);
	if (x < -range)
		_center.setX(range);
	if (y > range)
		_center.setY(-range);
	if (y < -range)
		_center.setY(range);
}

/**********************************************************************
 * Makes object dead if hit
 *************************************************************************/
void FlyingObject :: hit()
{
	_alive = false;
}

