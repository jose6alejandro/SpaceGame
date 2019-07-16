#ifndef _GAME_H
#define _GAME_H

#include "player.h"
#include "enemy.h"
#include "scenery.h"
#include "text.h"
#include "window.h"
#include "music.h"

typedef struct{

	unsigned int score;
	unsigned int life;
	unsigned int level;

	sfClock* clock;
    sfTime time;

}Attribute; 

Attribute attribute;

void gameDraw();
void gameAttributeLoad();

unsigned int gameRun();
unsigned int gameStart();
unsigned int gameEvents();
unsigned int gameGlobalBounds();

#endif //_GAME_H