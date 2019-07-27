#ifndef _TEXT_H
#define _TEXT_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <string.h>
#include "definition.h"
#include "../include/window.h"

typedef struct{

    sfFont* font;
    sfText* text;

    sfVector2f  vectorPosition,
                vectorScale,
                vectorOrigin;

}Text; 

Text textFont[7];

unsigned int textFontLoad(int);
void textLoad(unsigned int);
void textConfig(unsigned int i, sfText*, const char*, unsigned int,
                unsigned int, sfColor, unsigned int);

#endif //_TEXT_H