#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfTexture* texture;
    sfTexture* texture2;
    sfSprite* sprite;
    sfSprite* sprite2;

}Create;

Create resource;

typedef struct{
    
    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

}Sprite;

Sprite edit;

void assetsCreate();
void assetsLoad(Sprite);