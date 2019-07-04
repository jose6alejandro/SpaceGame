#include "../include/game.h"

int gameStart(){
   
    if (!(gameWindow(900, 800, 32, "SpaceGame")))
        return 1;
    
    sceneryLoad();

    enemyLoad();

    playerLoad();

    textGameOver();
    
    gameRun();

    return 0;
}

void gameRun(){

    while (sfRenderWindow_isOpen(game.window)){

        gameEvents(game.event);
        gameDraw(game.window);
    }

    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);

    sfSprite_destroy(enemy.sprite);
    sfTexture_destroy(enemy.texture);

    sfSprite_destroy(scenery.sprite);
    sfTexture_destroy(scenery.texture);

    sfText_destroy(textFont.text);
    sfFont_destroy(textFont.font);

    sfRenderWindow_destroy(game.window);     
}


void gameEvents(){

    while(sfRenderWindow_pollEvent(game.window, &game.event)){
        
        switch (game.event.type){

            case sfEvtClosed:
               sfRenderWindow_close(game.window);
            
            case sfEvtKeyPressed:

                switch(game.event.key.code){
                    
                    case sfKeyEscape:
                        sfRenderWindow_close(game.window);
                    
                    case sfKeyUp:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y - 3;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;
                    
                    case sfKeyDown:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y + 3;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;                                                    
                    
                    case sfKeyLeft:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x - 3;
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break; 

                    case sfKeyRight:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x + 3; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;
                }
        }
    }
}
void gameDraw(){

    sfRenderWindow_clear(game.window, sfColor_fromRGB(57, 161, 92));
    /**/

        sfRenderWindow_drawSprite(game.window, scenery.sprite, NULL); 
        sfRenderWindow_drawSprite(game.window, enemy.sprite, NULL); 
        sfRenderWindow_drawSprite(game.window, player.sprite, NULL);

        gameGlobalBounds();
        
    /**/
    sfRenderWindow_display(game.window);    
}

void gameGlobalBounds(){
    
    sfFloatRect playerRect = sfSprite_getGlobalBounds(player.sprite);
    sfFloatRect enemyRect = sfSprite_getGlobalBounds(enemy.sprite);
    
    if(sfFloatRect_intersects(&playerRect, &enemyRect, NULL)){

        sfSprite_setColor(player.sprite, sfColor_fromRGBA(250, 250, 250, 70));

            textFont.vectorPosition.x = sfRenderWindow_getSize(game.window).x / 2 - textSize * 100 / 50;
            textFont.vectorPosition.y = sfRenderWindow_getSize(game.window).y / 2 - textSize * 100 / 200;
            sfText_setPosition(textFont.text, textFont.vectorPosition);

        sfRenderWindow_drawText(game.window, textFont.text, NULL);
        
    }else{
         sfSprite_setRotation(enemy.sprite, sfSprite_getRotation(enemy.sprite) + 0.5);
         enemy.vectorPosition.x = sfSprite_getPosition(enemy.sprite).x; 
         enemy.vectorPosition.y = sfSprite_getPosition(enemy.sprite).y + 0.3;
         sfSprite_setPosition(enemy.sprite, (enemy.vectorPosition));
         sfSprite_setColor(player.sprite, sfColor_fromRGBA(250, 250, 250, 250));
    }
}

int gameWindow(unsigned int x, unsigned int y, 
                 unsigned int pixel, char* title){

    game.x = x;
    game.y = y;
    game.pixel = pixel;
    game.title = title;

    sfVideoMode mode = {game.x, game.y, game.pixel};
    
    game.window = sfRenderWindow_create(mode, game.title, sfResize | sfClose, NULL);

     if (game.window)
        return 1;

    return 0;
}


