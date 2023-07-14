/***********************************************************************
 * Source File:
 *    		Game
 * Author:
 *    	Aaron Picker
 * Summary:
 *   The brain of the game. Keeps everything updating and drawing.
 *   Handles collisions and removes dead objects.
 ************************************************************************/

#include "game.h"
#include "uiInteract.h"
#include "flyingObject.h"
// These are needed for the getClosestDistance function...
#include <limits>
#include <algorithm>
using namespace std;

/***********************************************************************
 * Initializes the game
 ************************************************************************/
Game :: Game(Point topLeft, Point bottomRight)
{
	this->topLeft = topLeft;
	this->bottomRight = bottomRight;
	addRocks(5);
	score = 0;
	shipCount = 3;
	gameOver = false;
}

/***********************************************************************
 * Advances all objects in the game
 ************************************************************************/
void Game :: advance ()
{
	for (int i = 0; i < rocks.size(); i++)
		rocks[i]->advance();
	if (rocks.size() == 0)
		addRocks(5);
	
	ship.advance();
	
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].isAlive())
			bullets[i].advance();
	
	handleCollisions();
	cleanUpZombies();
}

/***********************************************************************
 * Draws all objects n the game
 ************************************************************************/
void Game :: draw (const Interface& ui             )
{
	for (int i = 0; i < rocks.size(); i++)
		rocks[i]->draw();
	
	if (ship.isAlive())
		ship.draw();
	
	for (int i = 0; i < bullets.size(); i++)
		if (bullets[i].isAlive())
			bullets[i].draw();
	
	Point drawScore;
	drawScore.setX(topLeft.getX()+20);
	drawScore.setY(topLeft.getY()-10);
	drawNumber(drawScore, score);
	
	Point drawLives;
	drawLives.setX(topLeft.getX()+20);
	drawLives.setY(topLeft.getY()-30);
	for (int i = 0; i < shipCount; i++)
	{
		drawShip(drawLives, 0);
		drawLives.setX(drawLives.getX()+15);
	}
	
	if (gameOver == true)
		drawText((0, 0), "Game Over");
}

/***********************************************************************
 * Adds Big Rocks to the game, both at the start and if all rocks are destroyed.
 ************************************************************************/
void Game :: addRocks (int num)
{
	for (int i = 0; i < num; i++)
	{
		float x = (random(topLeft.getX(), bottomRight.getX()));
		float y = (random(bottomRight.getY(), topLeft.getY()));
		float dx = (random(-1.0, 1.0));
		float dy =(random(-1.0, 1.0));
		BigRock* big = new BigRock(x, y, dx, dy);
		rocks.push_back(big);
	}
}

/***********************************************************************
 * Gets user input and controls the ship/ fires bullets
 ************************************************************************/
void Game :: handleInput(const Interface &ui)
{
	if (ui.isUp())
	{
		ship.moveForward();
		ship.setThrust(true);
	}
	else
		ship.setThrust(false);
	
	if (ui.isLeft())
		ship.rotateLeft();
	
	if (ui.isRight())
		ship.rotateRight();
	
	if (ui.isSpace())
	{
		if (ship.isAlive())
		{
			Bullet bullet;
			bullet.fire(ship.getCenter(), ship.getAngle());
			bullets.push_back(bullet);
		}
	}
}

/***********************************************************************
 * Checks for collisions and removes anything that is hit
 ************************************************************************/
void Game :: handleCollisions()
{
	for (int i = 0; i < bullets.size(); i++)
		for (int j = 0; j < rocks.size(); j++)
		{
			if (bullets[i].isAlive() && rocks[j] != NULL && rocks[j]->isAlive())
			{
				if (fabs(bullets[i].getCenter().getX() - rocks[j]->getCenter().getX()) < CLOSE_ENOUGH
					 && fabs(bullets[i].getCenter().getY() - rocks[j]->getCenter().getY()) < CLOSE_ENOUGH)
				{
					rocks[j]->hit();
					if (rocks[j]->getRadius() == BIG_ROCK_SIZE)
					{
						breakBigRock((BigRock*)rocks[j]);
						points = 100;
					}
					else if (rocks[j]->getRadius() == MEDIUM_ROCK_SIZE)
					{
						breakMediumRock((MediumRock*)rocks[j]);
						points = 200;
					}
					else
						points = 250;
					
					score += points;
					
					bullets[i].hit();
				}
			}
		}
	
	for (int k = 0; k < rocks.size(); k++)
	{
		if (ship.isAlive() && rocks[k] != NULL && rocks[k]->isAlive())
		{
			if (fabs(ship.getCenter().getX() - rocks[k]->getCenter().getX()) < CLOSE_ENOUGH
				 && fabs(ship.getCenter().getY() - rocks[k]->getCenter().getY()) < CLOSE_ENOUGH)
			{
				rocks[k]->hit();
				ship.hit();
				shipCount -= 1;
				if (shipCount > 0)
					ship.resetShip();
				else
					gameOver = true;
				
				if (rocks[k]->getRadius() == BIG_ROCK_SIZE)
					//if (typeid(BigRock) == typeid(rocks[k]))
					breakBigRock((BigRock*)rocks[k]);
				else if (rocks[k]->getRadius() == MEDIUM_ROCK_SIZE)
					breakMediumRock((MediumRock*)rocks[k]);
			}
		}
	}
}

/***********************************************************************
 * Breaks the Big Rock apart, creating 3 smaller rocks
 ************************************************************************/
void Game :: breakBigRock (BigRock * rock)
{
	float x = rock->getCenter().getX();
	float y = rock->getCenter().getY();
	float dy = rock->getVelocity().getDy();
	float dx = rock->getVelocity().getDx();
	
	MediumRock* newRock1 = new MediumRock(x, y, dx, dy+1);
	MediumRock* newRock2 = new MediumRock(x, y, dx, dy-1);
	SmallRock* newRock3 = new SmallRock(x, y, dx+2, dy);
	
	rocks.push_back(newRock1);
	rocks.push_back(newRock2);
	rocks.push_back(newRock3);
}

/***********************************************************************
 * Breaks the Medium Rock, creating two Small Rocks
 ************************************************************************/
void Game :: breakMediumRock (MediumRock * rock)
{
	float x = rock->getCenter().getX();
	float y = rock->getCenter().getY();
	float dy = rock->getVelocity().getDy();
	float dx = rock->getVelocity().getDx();
	
	SmallRock* newRock1 = new SmallRock(x, y, dx+3, dy);
	SmallRock* newRock2 = new SmallRock(x, y, dx-3, dy);
	
	rocks.push_back(newRock1);
	rocks.push_back(newRock2);
}

/***********************************************************************
 * Eliminates any dead objects
 ************************************************************************/
void Game :: cleanUpZombies ()
{
	for (int j = 0; j < rocks.size(); j++)
	{
		if (rocks[j] != NULL && !rocks[j]->isAlive())
			rocks.erase(rocks.begin() + j);
	}
	
	vector<Bullet>::iterator bulletIt = bullets.begin();
	while (bulletIt != bullets.end())
	{
		Bullet bullet = *bulletIt;
		if (!bullet.isAlive())
			bulletIt = bullets.erase(bulletIt);
		else
			bulletIt++;
	}
}

// You may find this function helpful...

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
/*
 float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
 {
 // find the maximum distance traveled
 float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
 dMax = max(dMax, abs(obj2.getVelocity().getDx()));
 dMax = max(dMax, abs(obj2.getVelocity().getDy()));
 dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.
 
 float distMin = std::numeric_limits<float>::max();
 for (float i = 0.0; i <= dMax; i++)
 {
 Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
 obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
 Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
 obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));
 
 float xDiff = point1.getX() - point2.getX();
 float yDiff = point1.getY() - point2.getY();
 
 float distSquared = (xDiff * xDiff) +(yDiff * yDiff);
 
 distMin = min(distMin, distSquared);
 }
 
 return sqrt(distMin);
 }
 */

