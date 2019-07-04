#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfTexture* 	texture;
    sfSprite* 	sprite;

    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;
}Player;

Player player;

void playerLoad();
