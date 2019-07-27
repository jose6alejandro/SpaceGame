#ifndef _ENEMY_H
#define _ENEMY_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "definition.h"

typedef struct{

    sfTexture*  texture;
    sfSprite*   sprite;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

}Enemy;

Enemy enemy[30];

void enemyLoad(int);
void enemyDestroy(int);
void enemyConfig(unsigned int  x, unsigned int y, 
					float  scaleX, float scaleY, sfColor color);
#endif //_ENEMY_H