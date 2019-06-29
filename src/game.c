#include "../include/game.h"

/*
    Integrar componentes del juego
*/
int gamePlay(){

    
    if (!(WindowCreate(900, 800, 32, "SpaceGame")))
        return 1;

    assetsLoad(edit);
        
    gameLoop();
    
    gameClose();

    return 0;
}

/*
    Loop para ejecutar el juego 
*/
void gameLoop(){

    sfEvent event;

    while (sfRenderWindow_isOpen(win.window)){

        gameEvents(event);

        WindowDraw(win.window);
    }
}

/*
    Eventos del juego
*/
void gameEvents(sfEvent event){

    while(sfRenderWindow_pollEvent(win.window, &event)){
        if (event.type == sfEvtClosed){
               sfRenderWindow_close(win.window);
        }   
        if (event.type == sfEvtKeyPressed){

            if (sfKeyboard_isKeyPressed(sfKeyEscape)){
                   sfRenderWindow_close(win.window);
            }
            if (sfKeyboard_isKeyPressed(sfKeyUp)){
                  
                sfVector2f vectorPositionOn = {sfSprite_getPosition(resource.sprite).x, 
                                                   sfSprite_getPosition(resource.sprite).y -3};
                sfSprite_setPosition(resource.sprite, (vectorPositionOn));
            }
            if (sfKeyboard_isKeyPressed(sfKeyDown)){
                  
                sfVector2f vectorPositionOn = {sfSprite_getPosition(resource.sprite).x, 
                                                   sfSprite_getPosition(resource.sprite).y +3};
                sfSprite_setPosition(resource.sprite, (vectorPositionOn));
            }
            if (sfKeyboard_isKeyPressed(sfKeyLeft)){
                  
                sfVector2f vectorPositionOn = {sfSprite_getPosition(resource.sprite).x - 3, 
                                                   sfSprite_getPosition(resource.sprite).y};
                sfSprite_setPosition(resource.sprite, (vectorPositionOn));
            }
            if (sfKeyboard_isKeyPressed(sfKeyRight)){
                  
                sfVector2f vectorPositionOn = {sfSprite_getPosition(resource.sprite).x + 3, 
                                                   sfSprite_getPosition(resource.sprite).y};
                sfSprite_setPosition(resource.sprite, (vectorPositionOn));
            }
        }
    }
}

/*
    Cerrar todos los objetos y componentes del juego
*/
void gameClose(){

    sfSprite_destroy(resource.sprite);
    sfTexture_destroy(resource.texture);
    sfSprite_destroy(resource.sprite2);
    sfTexture_destroy(resource.texture2);
    sfRenderWindow_destroy(win.window); 
}