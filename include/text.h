#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define textSize 100

typedef struct{

    sfFont* font;
    sfText* text;
    
    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;

}Text; 

Text textFont;

void textGameOver();

