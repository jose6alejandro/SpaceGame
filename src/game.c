#include "../include/game.h"

int gameStart(){
   
    if (!(windowLoad(windowConfig,windowName)))
        return 1;

    timeLoad();
    
    sceneryLoad(1);

    enemyLoad();

    playerLoad();

    textFont.font = fontArial;
    
    for (int i = 0; i < 4; ++i){ textLoad(win.window, i); }

    musicLoad(1);

    sfRenderWindow_setFramerateLimit(win.window,FramerateLimit);

    gameRun();

    return 0;
}

void gameRun(){

    

    while (sfRenderWindow_isOpen(win.window)){
        
        timeUp.time = sfClock_getElapsedTime(timeUp.clock);
        
        /*if(bullet.clock != NULL){
            bullet.time = sfClock_getElapsedTime(bullet.clock);
        }*/
        
        sprintf(timeString,"%i",(int)sfTime_asSeconds(timeUp.time));
        
        char textChar[tam] = "Time ";
        sfText_setString(textFont.text2, strcat(textChar, timeString));
       
        gameEvents(win.event);
        
        playerhandleInput();          
       
        gameDraw(win.window);
    }

    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);
    
    if((bullet.sprite != NULL)  && (bullet.texture != NULL)){
        sfSprite_destroy(bullet.sprite);
        sfTexture_destroy(bullet.texture);       
    }

    sfSprite_destroy(enemy.sprite);
    sfTexture_destroy(enemy.texture);

    sfSprite_destroy(scenery.sprite);
    sfTexture_destroy(scenery.texture);
    
    /*sfFont_destroy(textFont.font);
    sfText_destroy(textFont.text);*/

    sfClock_destroy(bullet.clock);
    sfClock_destroy(timeUp.clock);
    
    musicClean(1);

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

    sfRenderWindow_clear(win.window, colorTertiary);
    /**/

        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawSprite(win.window, enemy.sprite, NULL); 
        sfRenderWindow_drawSprite(win.window, player.sprite, NULL);
        sfRenderWindow_drawText(win.window, textFont.text2, NULL);
        sfRenderWindow_drawText(win.window, textFont.text3, NULL);
        sfRenderWindow_drawText(win.window, textFont.text4, NULL);
        
        if((bullet.sprite != NULL) && (bullet.texture != NULL)){
            //bulletUpdate();
            sfRenderWindow_drawSprite(win.window, bullet.sprite, NULL);           
            bulletMove(0,- 40);
        }
        
        unsigned int flag = gameGlobalBounds();

        if(flag == 1){
            sfSprite_setColor(player.sprite, colorInvisible);
            //sfTime time2 = sfClock_restart(timeUp.clock);
            sfRenderWindow_drawText(win.window, textFont.text, NULL);        
            //sfSleep(sfMilliseconds(800));             
        }else{
         sfSprite_setRotation(enemy.sprite, sfSprite_getRotation(enemy.sprite) + 0.5);
         enemy.vectorPosition.x = sfSprite_getPosition(enemy.sprite).x; 
         enemy.vectorPosition.y = sfSprite_getPosition(enemy.sprite).y + 0.3;
         sfSprite_setPosition(enemy.sprite, (enemy.vectorPosition));
         sfSprite_setColor(player.sprite, colorNone);
        }
     
        
    /**/
    sfRenderWindow_display(win.window);    
}

unsigned int gameGlobalBounds(){
    
    sfFloatRect playerRect = sfSprite_getGlobalBounds(player.sprite);
    sfFloatRect enemyRect = sfSprite_getGlobalBounds(enemy.sprite);
    
    if(sfFloatRect_intersects(&playerRect, &enemyRect, NULL))
        return 1;    

    return 0;
    
}

