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
        
        playerhandleInput();          
        
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
        
        if(win.event.type == sfEvtClosed){

            sfRenderWindow_close(win.window);
        }  
        if(win.event.key.code == sfKeyEscape){
        
            sfRenderWindow_close(win.window);
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

