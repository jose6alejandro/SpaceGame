#ifndef _BULLET_H
#define _BULLET_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfTexture*  texture;
    sfSprite*   sprite;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

    sfVector2f  velocity,
    			accelerate;  

    sfClock*    clock;
    sfTime      time;
    unsigned int time2;

}Bullet;

Bullet bullet;

void bulletMove(int x, int y);
void bulletLoad(sfSprite*);
//void bulletUpdate(sfSprite*);

#endif //_BULLET_H