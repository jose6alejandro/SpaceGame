#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bullet.h"
#include "definition.h"

typedef struct{

    sfTexture*  texture;
    sfSprite*   sprite;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;
        
}Player;

Player player;

void playerLoad();
void playerConfig(unsigned int  x, unsigned int y, float  scaleX, 
					float scaleY, sfColor color);
void playerMove(int, int);
void playerhandleInput();


#endif //_PLAYER_H