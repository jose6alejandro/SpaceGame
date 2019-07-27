#include "../include/game.h"
#include "../include/menu.h"
#include <stdio.h>

unsigned int boolean[tam * 2] = {0};

unsigned int gameStart(){
   
    if (!(windowLoad(windowConfig,windowName)))
        return 1;
    
    sceneryLoad(1);
    
    gameAttributeLoad();
    
    playerLoad();

    enemyLoad(0);
    
    textFontLoad(6);

    musicLoad(1);

    sfRenderWindow_setFramerateLimit(win.window,FramerateLimit);

    gameRun();

    return 0;
}

unsigned int gameRun(){
    

    while (sfRenderWindow_isOpen(win.window)){
        
        unsigned int flag = gameGlobalBounds();
        unsigned int flag2 = gameEvents();

        if (flag == 0 /*no colitions*/){
            attribute.time = sfClock_getElapsedTime(attribute.clock);
            playerhandleInput();           
        }

        if(flag2 == 2){
            sfRenderWindow_close(win.window);
            musicClean(1);
            return 0;
        }

        if(flag == 1 && flag2 == 1){
            sfRenderWindow_close(win.window);
            musicClean(1);
            attribute.life = 3; 
            return menuExecute();
        }
        gameAttributeView("Time ", (int)sfTime_asSeconds(attribute.time), 2);

        if((int)sfTime_asSeconds(attribute.time) == 2 + attribute.time2){
            
            attribute.time2 = (int)sfTime_asSeconds(attribute.time);

            if ((rand() % 100 + 1) < 85){
                for (int i = 0; i < tam * 2; ++i){
                    if (!boolean[i]){
                        boolean[i] = 1;

                        sfSprite_setTexture(enemy[i].sprite, enemy[i].texture, sfTrue);
                        enemy[i].vectorPosition.x = rand() % 650 + 100;
                        enemy[i].vectorPosition.y = 40;
                        sfSprite_setPosition(enemy[i].sprite, enemy[i].vectorPosition);
                        enemy[i].vectorOrigin.x = sfTexture_getSize(enemy[i].texture).x/2; 
                        enemy[i].vectorOrigin.y = sfTexture_getSize(enemy[i].texture).y/2;
                        sfSprite_setOrigin(enemy[i].sprite, enemy[i].vectorOrigin);  

                        break;
                    }

                }
            }
           
        }
        gameDraw();

    }

    gameClose();

    return 0;     
}


unsigned int gameEvents(){

    while(sfRenderWindow_pollEvent(win.window, &win.event)){
        
        if(win.event.type == sfEvtClosed)
            return 2;
     
        if(win.event.key.code == sfKeyEscape)
            return 1;       
    }

    return 0;
}

void gameDraw(){

    sfRenderWindow_clear(win.window, colorTertiary);
    /**/

        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawSprite(win.window, player.sprite, NULL);
        
        if((bullet.sprite != NULL) && (bullet.texture != NULL)){
            sfRenderWindow_drawSprite(win.window, bullet.sprite, NULL);           
            bulletMove(0,- 40);
        }

        for (int i = 0; i < 4; ++i)
            sfRenderWindow_drawText(win.window, textFont[i+2].text, NULL);
        
        unsigned int flag = gameGlobalBounds();

        if(flag == 1){
            sfSprite_setColor(player.sprite, colorInvisible);
            sfRenderWindow_drawText(win.window, textFont[0].text, NULL);     
            sfRenderWindow_drawText(win.window, textFont[1].text, NULL);    
        }else{

            for (int i = 0; i < tam * 2; ++i){
                 if(enemy[i].sprite != NULL){
                   sfRenderWindow_drawSprite(win.window, enemy[i].sprite, NULL);
                    sfSprite_setRotation(enemy[i].sprite, sfSprite_getRotation(enemy[i].sprite) + 0.5);
                    enemy[i].vectorPosition.x = sfSprite_getPosition(enemy[i].sprite).x; 
                    
                    enemy[i].vectorPosition.y = ((int)sfTime_asSeconds(attribute.time) < 15)  ?
                                                sfSprite_getPosition(enemy[i].sprite).y + 0.7 :
                                                ((int)sfTime_asSeconds(attribute.time) > 15 && 
                                                (int)sfTime_asSeconds(attribute.time) < 30)   ?   
                                                sfSprite_getPosition(enemy[i].sprite).y + 0.9 :
                                                sfSprite_getPosition(enemy[i].sprite).y + 1.1;
                    
                    sfSprite_setPosition(enemy[i].sprite, (enemy[i].vectorPosition));
                    sfSprite_setColor(player.sprite, colorNone);                
                }
            }            
        }
    
    /**/
    sfRenderWindow_display(win.window);    
}

unsigned int gameGlobalBounds(){
    
    sfFloatRect playerRect = sfSprite_getGlobalBounds(player.sprite);
    sfFloatRect enemyRect[tam * 2];

    for (int i = 0; i < tam * 2; ++i){
        if(enemy[i].sprite != NULL){
            enemyRect[i] = sfSprite_getGlobalBounds(enemy[i].sprite);             
        }
    }   
        if((bullet.sprite != NULL) && (bullet.texture != NULL)){
            sfFloatRect bulletRect = sfSprite_getGlobalBounds(bullet.sprite);
            
            for (int i = 0; i < tam * 2; ++i){
                if(sfFloatRect_intersects(&bulletRect, &enemyRect[i], NULL)){
                    enemy[i].sprite = NULL;
                    bullet.sprite = NULL;
                    attribute.score += 50;
                    gameAttributeView("Score ", attribute.score, 5);

                  return 2;
                }
            }                  
        }

        if (attribute.life == 0)
            return 1; 

         for (int i = 0; i < tam * 2; ++i){
            if(sfFloatRect_intersects(&playerRect, &enemyRect[i], NULL)){
                attribute.life -= 1;                 
                gameAttributeView("Nave x ", attribute.life, 4);
                player.vectorPosition.x = 400;
                player.vectorPosition.y = 500;
                sfSprite_setPosition(player.sprite, player.vectorPosition);
            }
        }       
         
   
   
    return 0;
    
}

void gameAttributeLoad(){
    attribute.score = 0;
    attribute.time2 = 0;
    attribute.life  = 3;
    attribute.clock = sfClock_create();
}

void gameAttributeView(char *stringCopy, int i, int position){
    char string[tam];
    char timeString[5];
    strcpy(string, stringCopy);
    sprintf(timeString,"%i",i);
    sfText_setString(textFont[position].text, strcat(string, timeString));
}

void gameClose(){

    if((bullet.sprite != NULL) && (bullet.texture != NULL))
        sfSprite_destroy(bullet.sprite), sfTexture_destroy(bullet.texture);       

    sfSprite_destroy(player.sprite);
    sfTexture_destroy(player.texture);
    sfSprite_destroy(scenery.sprite);
    sfTexture_destroy(scenery.texture);
    sfClock_destroy(attribute.clock);

    enemyDestroy(0);
    musicClean(1);

    sfRenderWindow_destroy(win.window);

}

