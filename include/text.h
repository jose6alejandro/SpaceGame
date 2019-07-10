#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define textSize 100

typedef struct{

    sfFont* font;
    sfFont* font2;

    sfText* text;
    sfText* text2;
    
    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;
}Text; 

Text textFont;
char timeString [3];

void textGameOver();
void textTime(sfRenderWindow*);