/***********************************************************************
 * Header File:
 *    Bullet
 * Author:
 *    	Aaron Picker
 * Summary:
 *   Creates and handles bullets
 ************************************************************************/

#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40

#include "flyingObject.h"
#include "uiDraw.h"

class Bullet : public FlyingObject
{
private:
	int _frameCount;
public:
	Bullet()          {_frameCount = BULLET_LIFE; }
	void draw();
	void fire(const Point &p, const float &angle);
	void advance();
};
#endif /* bullet_h */
