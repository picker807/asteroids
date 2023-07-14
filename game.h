/***********************************************************************
 * Header File:
 *    		Game
 * Author:
 *    	Aaron Picker
 * Summary:
 *   The brain of the game. Keeps everything updating and drawing.
 ************************************************************************/

#ifndef GAME_H
#define GAME_H
#include "velocity.h"
#include "uiInteract.h"
#include "uiDraw.h"
#include "ship.h"
#include "rocks.h"
#include "point.h"
#include "bullet.h"
#include <vector>
#include <list>
#define CLOSE_ENOUGH 15

using namespace std;

class Game
{
private:
	Point topLeft;
	Point bottomRight;
	Ship ship;
	vector <Rock*> rocks;
	vector <Bullet> bullets;
	int shipCount;
	int points;
	int score;
	bool gameOver;
public:
	Game (Point topLeft, Point bottomRight);
	void advance             (                                );
	void handleInput         (const Interface& ui             );
	void draw                (const Interface& ui             );
	void addRocks            (int count                       );
	void handleCollisions    (                                );
	void breakBigRock        (BigRock * rock                  );
	void breakMediumRock     (MediumRock * rock               );
	void cleanUpZombies      (                                );
};

#endif /* GAME_H */
