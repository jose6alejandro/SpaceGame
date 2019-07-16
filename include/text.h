#ifndef _TEXT_H
#define _TEXT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <string.h>
#include "definition.h"

typedef struct{

    sfFont* font;
    sfText* text;
    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

}Text; 

Text textFont[7];
char timeString [3];
char timeString2 [3];

void textLoad(sfRenderWindow*, unsigned int);
void textConfig(unsigned int, sfRenderWindow*, sfText*,
                const char*, unsigned int,
                unsigned int, sfColor, unsigned int);

#endif //_TEXT_H