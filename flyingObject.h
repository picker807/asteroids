/***********************************************************************
 * Header File:
 *    	Flying Object
 * Author:
 *    	Aaron Picker
 * Summary:
 *   	Base class for all objects that move in the game
 ************************************************************************/

#ifndef flyingObject_h
#define flyingObject_h
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
protected:
	Velocity _velocity;
	bool _alive;
	int _angle;
	Point _center;
	int _radius;
public:
	FlyingObject();
	Point getCenter()              {return _center;       }
	Velocity getVelocity()         {return _velocity;     }
	bool isAlive();
	virtual void advance();
	virtual void draw()            {                      }
	virtual void hit();
};

#endif /* flyingObject_h */

