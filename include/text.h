#ifndef _TEXT_H
#define _TEXT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "definition.h"

typedef struct{

    sfFont* font;
    sfText* text;
    sfText* text2;
    sfText* text3;
    
    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;
}Text; 

Text textFont;
char timeString [3];

void textMenuLoad(sfRenderWindow*);
void textLoad(sfRenderWindow*, int);
#endif //_TEXT_H