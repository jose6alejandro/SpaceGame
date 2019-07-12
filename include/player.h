#ifndef _PLAYER_H
#define _PLAYER_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "bullet.h"

typedef struct{

    sfTexture*  texture;
    sfSprite*   sprite;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;
        
}Player;

Player player;

void playerLoad();
void playerhandleInput();
void playerMove(int, int);

#endif //_PLAYER_H