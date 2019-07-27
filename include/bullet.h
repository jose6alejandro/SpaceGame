#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "definition.h"

typedef struct{

    sfTexture*  texture;
    sfSprite*   sprite;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

}Bullet;

Bullet bullet;

void bulletLoad(sfSprite*);
void bulletConfig(unsigned int  x, unsigned int y, 
                    float  scaleX, float scaleY, sfColor color);
void bulletMove(int x, int y);


#endif //_BULLET_H