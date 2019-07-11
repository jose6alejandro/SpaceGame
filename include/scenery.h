#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfTexture* 	texture;
    sfSprite* 	sprite;

    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;
}Scenery;

Scenery scenery;

void sceneryLoad(int);