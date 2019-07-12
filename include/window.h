#ifndef _WINDOW_H
#define _WINDOW_H

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "definition.h"

typedef struct{

    sfRenderWindow* window;
    sfEvent event;
    char* title; 
    unsigned int x,
                 y, 
                 pixel;
}Window; 

Window win;

int  windowLoad(unsigned int, unsigned int, 
                 unsigned int, char*);

#endif //_WINDOW_H