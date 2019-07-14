#include "../include/game.h"
#include "../include/menu.h"
#include <stdio.h>
unsigned int gameStart(){
   
    if (!(windowLoad(windowConfig,windowName)))
        return 1;

    timeLoad();
    
    sceneryLoad(1);

    enemyLoad();

    playerLoad();
    
    for (int i = 0; i < 6; ++i)
    {
        textFont[i].font = fontArial;
    }
    
    textLoad(win.window, 0);
    textLoad(win.window, 1);

    musicLoad(1);

    sfRenderWindow_setFramerateLimit(win.window,FramerateLimit);

    gameRun();

    return 0;
}

unsigned int gameRun(){

    while (sfRenderWindow_isOpen(win.window)){
        
        int flag = gameGlobalBounds();

        if (!flag == 1){
            timeUp.time = sfClock_getElapsedTime(timeUp.clock);
            playerhandleInput();           
        }  
        
        sprintf(timeString,"%i",(int)sfTime_asSeconds(timeUp.time));
        char textChar[tam] = "Time ";
        sfText_setString(textFont[2].text, strcat(textChar, timeString));
       
        int flag2 = gameEvents(win.event);
        
        if(flag == 1 && flag2 == 1){
            sfRenderWindow_close(win.window);
            musicClean(1);
            return menuExecute();
        }
        if(flag2 == 2){
            sfRenderWindow_close(win.window);
            musicClean(1);
            return 0;
        }

        gameDraw();
    }


    if((bullet.sprite != NULL)  || (bullet.texture != NULL)){
        sfSprite_destroy(bullet.sprite);
        sfTexture_destroy(bullet.texture);       
    }

    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);

    if((enemy.sprite != NULL)){
        sfSprite_destroy(enemy.sprite);
    }

    sfTexture_destroy(enemy.texture);
    sfSprite_destroy(bullet.sprite);
    sfTexture_destroy(bullet.texture);

    sfSprite_destroy(scenery.sprite);
    sfTexture_destroy(scenery.texture);
    
    /*sfFont_destroy(textFont[i].font);
    sfText_destroy(textFont[i].text);*/

    sfClock_destroy(timeUp.clock);
    
    musicClean(1);
    sfRenderWindow_destroy(win.window);

    return 0;     
}


unsigned int gameEvents(){

    while(sfRenderWindow_pollEvent(win.window, &win.event)){
        
        if(win.event.type == sfEvtClosed){
            return 2;
        }  
        if(win.event.key.code == sfKeyEscape){
            return 1;
        }
    }
    return 0;
}

void gameDraw(){

    sfRenderWindow_clear(win.window, colorTertiary);
    /**/

        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
      
        if(enemy.sprite != NULL){
           sfRenderWindow_drawSprite(win.window, enemy.sprite, NULL); 

        }
        
        sfRenderWindow_drawSprite(win.window, player.sprite, NULL);

        sfRenderWindow_drawText(win.window, textFont[2].text, NULL);
        sfRenderWindow_drawText(win.window, textFont[3].text, NULL);
        sfRenderWindow_drawText(win.window, textFont[4].text, NULL);
        sfRenderWindow_drawText(win.window, textFont[5].text, NULL); 

        if((bullet.sprite != NULL) && (bullet.texture != NULL)){
            //bulletUpdate();
            sfRenderWindow_drawSprite(win.window, bullet.sprite, NULL);           
            bulletMove(0,- 40);
        }
        
        unsigned int flag = gameGlobalBounds();

        if(flag == 1){
            sfSprite_setColor(player.sprite, colorInvisible);
            //sfTime time2 = sfClock_restart(timeUp.clock);
            sfRenderWindow_drawText(win.window, textFont[0].text, NULL);     
            sfRenderWindow_drawText(win.window, textFont[1].text, NULL);    
            //sfSleep(sfMilliseconds(800));

        }else{
            if((enemy.sprite != NULL)){
                sfSprite_setRotation(enemy.sprite, sfSprite_getRotation(enemy.sprite) + 0.5);
                enemy.vectorPosition.x = sfSprite_getPosition(enemy.sprite).x; 
                enemy.vectorPosition.y = sfSprite_getPosition(enemy.sprite).y + 0.3;
                sfSprite_setPosition(enemy.sprite, (enemy.vectorPosition));
                sfSprite_setColor(player.sprite, colorNone);
            }
        }

     
        
    /**/
    sfRenderWindow_display(win.window);    
}

unsigned int gameGlobalBounds(){
    
    sfFloatRect playerRect = sfSprite_getGlobalBounds(player.sprite);
    if(enemy.sprite != NULL){
        sfFloatRect enemyRect = sfSprite_getGlobalBounds(enemy.sprite);
    
   
        if((bullet.sprite != NULL) || (bullet.texture != NULL)){
            sfFloatRect bulletRect = sfSprite_getGlobalBounds(bullet.sprite);
            
            if(sfFloatRect_intersects(&bulletRect, &enemyRect, NULL)){
              enemy.sprite = NULL; 
              //enemy.texture = NULL; 
            }    
        }

        if(sfFloatRect_intersects(&playerRect, &enemyRect, NULL)){
            return 1;    
        }
    }
   
    return 0;
    
}

