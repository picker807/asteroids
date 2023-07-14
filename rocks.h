/***********************************************************************
 * Header File:
 *    Rocks
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Creates and handles Asteroids of all sizes.
 ************************************************************************/

#ifndef rocks_h
#define rocks_h

#include "flyingObject.h"
#include "uiDraw.h"
#include "vector"

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

/***********************************************************************
 * Rock: Base class for all rocks.
 ************************************************************************/
class Rock : public FlyingObject
{
protected:
	int _spinSpeed;
public:
	Rock()                  {                                              }
	int getRadius()         { return _radius;                              }
	void advance()          {_angle += _spinSpeed; FlyingObject::advance();}
	virtual void draw()     {                                              }
};

/***********************************************************************
 * Big Rock Class
 ************************************************************************/
class BigRock : public Rock
{
public:
	BigRock(float x, float y, float dx, float dy);
	void draw();
};

/***********************************************************************
 * Medium Rock Class
 ************************************************************************/
class MediumRock : public Rock
{
public:
	MediumRock(float x, float y, float dx, float dy);
	void draw();
};

/***********************************************************************
 * Small Rock Class
 ************************************************************************/
class SmallRock : public Rock
{
public:
	SmallRock(float x, float y, float dx, float dy);
	void draw();
};

#endif /* rocks_h */
