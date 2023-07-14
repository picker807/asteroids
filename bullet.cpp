/***********************************************************************
 * Source File:
 *    Bullet
 * Author:
 *    	Aaron Picker
 * Summary:
 *	Creates and handles the bullets
 ************************************************************************/

#include "bullet.h"
#include <cmath>

/*********************************************************************
 * Draw the Bullets
 ************************************************************************/
void Bullet :: draw()
{
	drawDot(getCenter());
}

/*********************************************************************
 *	Set bullet trajectory
 ************************************************************************/
void Bullet :: fire (const Point &p, const float &angle)
{
	_center.setX(p.getX());
	_center.setY(p.getY());
	_velocity.setDx(-sin(2 * M_PI * (angle / 360)) * BULLET_SPEED);
	_velocity.setDy(cos(2 * M_PI * (angle / 360)) * BULLET_SPEED);
}

/*********************************************************************
 *	Move the bullet
 ************************************************************************/
void Bullet :: advance()
{
	_frameCount -=1;
	if (_frameCount <= 0)
		FlyingObject :: hit();
	FlyingObject :: advance();
}

