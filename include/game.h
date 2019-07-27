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
	unsigned int time2;
	sfClock* clock;
    sfTime time;

}Attribute; 

Attribute attribute;

void gameDraw();
void gameAttributeLoad();
void gameAttributeView(char *, int, int);
void gameClose();

unsigned int gameRun();
unsigned int gameStart();
unsigned int gameEvents();
unsigned int gameGlobalBounds();

#endif //_GAME_H