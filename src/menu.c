#include "../include/menu.h"

int menuExecute(){

    if (!(windowLoad(windowConfig,windowName)))
        return 1;

    unsigned int flag = 0;

    sceneryLoad(0);

    musicLoad(0);
    
    sfMusic_setLoop(music.soundLong, sfTrue);
    sfMusic_play(music.soundLong);

    
    textMenuLoad(win.window); 

    sfRenderWindow_setFramerateLimit(win.window,FramerateLimit);

    while (sfRenderWindow_isOpen(win.window)){

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
                            sfSound_play(music.soundShort);
                            sfText_setColor(textFont.text, colorPrimary);
                            sfText_setColor(textFont.text2, colorSecondary);
                            flag = 0;
                            break;
                                
                        case sfKeyDown:
                            sfSound_play(music.soundShort2);
                            sfText_setColor(textFont.text2, colorPrimary);
                            sfText_setColor(textFont.text, colorSecondary);
                            flag = 1;
                            break; 

                        case sfKeyReturn:
                        case sfKeySpace:
                                
                            if(!flag == 0){
                                sfRenderWindow_close(win.window);
                            }
                            else{
                                sfRenderWindow_close(win.window);
                                //sfMusic_stop(music.soundLong);
                                musicClean(0);
                                return gameStart();
                            }
                            break;   
                    }
            }
        }

        menuDraw();   
    }

        musicClean(0);
        sfFont_destroy(textFont.font);
        sfText_destroy(textFont.text);
        sfText_destroy(textFont.text2);
        sfText_destroy(textFont.text3);
        sfSprite_destroy(scenery.sprite);
        sfTexture_destroy(scenery.texture);
        sfRenderWindow_destroy(win.window);
        
    return 0;
}

void menuDraw(){
    sfRenderWindow_clear(win.window, colorTertiary);
    /**/
        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawText(win.window, textFont.text, NULL);
        sfRenderWindow_drawText(win.window, textFont.text2, NULL);
        sfRenderWindow_drawText(win.window, textFont.text3, NULL);
    /**/
    sfRenderWindow_display(win.window);    
}