#include "../include/game.h"

int gameStart(){
   
    if (!(windowLoad(900, 800, 32, "SpaceGame")))
        return 1;
    
    textFont.font = sfFont_createFromFile("assets/arial.ttf");
    
    timeLoad();
    
    sceneryLoad(1);

    enemyLoad();

    playerLoad();

    textGameOver(win.window);
    
    textTime(win.window);
      
    gameRun();

    return 0;
}

void gameRun(){

    while (sfRenderWindow_isOpen(win.window)){

        timeUp.time = sfClock_getElapsedTime(timeUp.clock);
        sprintf(timeString,"%i",(int)sfTime_asSeconds(timeUp.time));
        sfText_setString(textFont.text2, timeString);
        
        gameEvents(win.event);
        gameDraw(win.window);
    }

    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);

    sfSprite_destroy(enemy.sprite);
    sfTexture_destroy(enemy.texture);

    sfSprite_destroy(scenery.sprite);
    sfTexture_destroy(scenery.texture);
    
    sfFont_destroy(textFont.font);
    sfText_destroy(textFont.text);
    sfText_destroy(textFont.text2);


    sfClock_destroy(timeUp.clock);

    sfRenderWindow_destroy(win.window);     
}


void gameEvents(){

    while(sfRenderWindow_pollEvent(win.window, &win.event)){
        
        switch (win.event.type){

            case sfEvtClosed:
               sfRenderWindow_close(win.window);
            
            case sfEvtKeyPressed:

                switch(win.event.key.code){
                    
                    case sfKeyEscape:
                        sfRenderWindow_close(win.window);
                        break;

                    case sfKeyUp:
                    case sfKeyW:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y - 3;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;
                    
                    case sfKeyDown:
                    case sfKeyS:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y + 3;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;                                                    
                    
                    case sfKeyLeft:
                    case sfKeyA:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x - 3;
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break; 

                    case sfKeyRight:
                    case sfKeyD:
                        player.vectorPosition.x = sfSprite_getPosition(player.sprite).x + 3; 
                        player.vectorPosition.y = sfSprite_getPosition(player.sprite).y;
                        sfSprite_setPosition(player.sprite, (player.vectorPosition));
                        break;

                    default:
                        //Nota: perfeccionar el movimiento
                        break;
                }
        }
    }
}
void gameDraw(){

    sfRenderWindow_clear(win.window, sfColor_fromRGB(57, 161, 92));
    /**/

        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawSprite(win.window, enemy.sprite, NULL); 
        sfRenderWindow_drawSprite(win.window, player.sprite, NULL);
        sfRenderWindow_drawText(win.window, textFont.text2, NULL);
        
        /*if((int)sfTime_asSeconds(timeUp.time) == 10){
            //sfRenderWindow_drawText(win.window, textFont.text, NULL);
            
            //timeUp.time = sfClock_restart(timeUp.clock);
        }*/

        gameGlobalBounds();
        
    /**/
    sfRenderWindow_display(win.window);    
}

void gameGlobalBounds(){
    
    sfFloatRect playerRect = sfSprite_getGlobalBounds(player.sprite);
    sfFloatRect enemyRect = sfSprite_getGlobalBounds(enemy.sprite);
    
    if(sfFloatRect_intersects(&playerRect, &enemyRect, NULL)){

        sfSprite_setColor(player.sprite, sfColor_fromRGBA(250, 250, 250, 70));

        sfRenderWindow_drawText(win.window, textFont.text, NULL);
         
        //sfSleep(sfMilliseconds(800));
        
                
    }else{
         sfSprite_setRotation(enemy.sprite, sfSprite_getRotation(enemy.sprite) + 0.5);
         enemy.vectorPosition.x = sfSprite_getPosition(enemy.sprite).x; 
         enemy.vectorPosition.y = sfSprite_getPosition(enemy.sprite).y + 0.3;
         sfSprite_setPosition(enemy.sprite, (enemy.vectorPosition));
         sfSprite_setColor(player.sprite, sfColor_fromRGBA(250, 250, 250, 250));
    }
    
}
