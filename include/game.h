#ifndef _GAME_H
#define _GAME_H

#include "player.h"
#include "enemy.h"
#include "scenery.h"
#include "text.h"
#include "time.h"
#include "window.h"
#include "music.h"

int  gameStart();
void gameRun();
void gameEvents();
void gameDraw();
unsigned int gameGlobalBounds();

#endif //_GAME_H