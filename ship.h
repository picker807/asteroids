/***********************************************************************
 * Header File:
 *    Ship
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Creates and handles the ship
 ************************************************************************/

#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#include <cmath>
#include "uiDraw.h"

#define SHIP_SIZE 10
#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5


class Ship : public FlyingObject
{
private:
	float _thrust;
	bool thrustOn;
public:
	Ship()                       {_angle = 0; _thrust = THRUST_AMOUNT; _radius = SHIP_SIZE;}
	void advance()               {FlyingObject::advance();                                 }
	float getAngle();
	void moveForward();
	void rotateLeft();
	void rotateRight();
	void draw();
	void setThrust(bool a);
	void resetShip();
};

#endif /* ship_h */
