#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#define textSize 100

typedef struct{

    sfFont* font;
    sfText* text;
    sfText* text2;
    sfText* text3;
    
    sfVector2f 	vectorPosition,
                vectorScale,
                vectorOrigin;
}Text; 

Text textFont;
char timeString [3];

void textGameOver(sfRenderWindow*);
void textTime(sfRenderWindow*);
void textMenu(sfRenderWindow*);