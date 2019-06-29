#include "../include/window.h"

/*
    Dibujar dentro de la ventana
*/
void WindowDraw(){

    sfRenderWindow_clear(win.window, sfColor_fromRGB(57, 161, 92));
    /**/
        sfRenderWindow_drawSprite(win.window, resource.sprite2, NULL); // textura del fondo
        sfRenderWindow_drawSprite(win.window, resource.sprite, NULL);  // textura de la nave
    /**/
    sfRenderWindow_display(win.window);    
}

/*
    Crear y ajustar la ventana
*/
int WindowCreate(unsigned int x, unsigned int y, 
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
