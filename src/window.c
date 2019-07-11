#include "../include/window.h"

int windowLoad(unsigned int x, unsigned int y, 
                 unsigned int pixel, char* title){

    win.x = x;
    win.y = y;
    win.pixel = pixel;
    win.title = title;

    sfVideoMode mode = {win.x, win.y, win.pixel};
    
    win.window = sfRenderWindow_create(mode, win.title, sfResize | sfClose, NULL);

     if (win.window)
        return 1;

    return 0;
}
