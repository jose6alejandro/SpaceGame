#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define tam 15

typedef struct{

    sfTexture* 	texture;
    sfSprite* 	sprite;

    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;
}Enemy;

Enemy enemy;

int enemyNum();
void enemyLoad();
