/***********************************************************************
 * Header File:
 *    Velocity
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Every Flying Object has a velocity.
 ************************************************************************/

#ifndef VELOCITY_H
#define VELOCITY_H

#include <iostream>

class Velocity
{
private:
	float _dx;
	float _dy;
	
public:
	Velocity()               {_dx = 0; _dy = 0;   }
	float getDx()            { return _dx;        }
	float getDy()            { return _dy;        }
	void setDx(float x)      { _dx = x;           }
	void setDy(float y)      { _dy = y;           }
};

#endif /* velocity_h */
