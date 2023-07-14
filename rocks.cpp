/***********************************************************************
 * Source File:
 *    Rocks
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Creates and handles Asteroids of all sizes.
 ************************************************************************/

#include "rocks.h" 

/*************************************************************************************************
 * Big Rock Constructor - child of Rock Class
 *****************************************************************************************************/
//   BigRock
BigRock :: BigRock(float x, float y, float dx, float dy)
{
	int dir = random(0, 1);
	if (dir == 1)
		_spinSpeed = BIG_ROCK_SPIN;
	else
		_spinSpeed = -BIG_ROCK_SPIN;
	
	_radius = BIG_ROCK_SIZE;
	_angle = random(0, 360);
	_center.setX(x);
	_center.setY(y);
	_velocity.setDx(dx);
	_velocity.setDy(dy);
};

/***********************************************************************
 * Draw Big Rock
 ************************************************************************/
void BigRock :: draw()
{
	drawLargeAsteroid(getCenter(), _angle);
}

/***********************************************************************
 * Medium Rock Constructor
 ************************************************************************/
MediumRock :: MediumRock(float x, float y, float dx, float dy)
{
	int dir = random(0, 1);
	if (dir == 1)
		_spinSpeed = MEDIUM_ROCK_SPIN;
	else
		_spinSpeed = -MEDIUM_ROCK_SPIN;
	
	_radius = MEDIUM_ROCK_SIZE;
	_angle = random(0, 360);
	_center.setX(x);
	_center.setY(y);
	_velocity.setDx(dx);
	_velocity.setDy(dy);
};

/***********************************************************************
 * Draw Medium Rock
 ************************************************************************/
void MediumRock :: draw()
{
	drawMediumAsteroid(getCenter(), _angle);
}

/***********************************************************************
 * Small Rock Constructor
 ************************************************************************/
SmallRock :: SmallRock(float x, float y, float dx, float dy)
{
	int dir = random(0, 1);
	if (dir == 1)
		_spinSpeed = SMALL_ROCK_SPIN;
	else
		_spinSpeed = -SMALL_ROCK_SPIN;
	
	_radius = SMALL_ROCK_SIZE;
	_angle = random(0, 360);
	_center.setX(x);
	_center.setY(y);
	_velocity.setDx(dx);
	_velocity.setDy(dy);
};

/***********************************************************************
 * Draw Small Rock
 ************************************************************************/
void SmallRock :: draw()
{
	drawSmallAsteroid(getCenter(), _angle);
}
