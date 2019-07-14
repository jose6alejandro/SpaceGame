#ifndef _GAME_H
#define _GAME_H

#include "player.h"
#include "enemy.h"
#include "scenery.h"
#include "text.h"
#include "time.h"
#include "window.h"
#include "music.h"

void gameDraw();

unsigned int gameRun();
unsigned int gameStart();
unsigned int gameEvents();
unsigned int gameGlobalBounds();

#endif //_GAME_H