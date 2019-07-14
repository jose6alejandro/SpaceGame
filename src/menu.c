#include "../include/menu.h"

int menuExecute(){

    if (!(windowLoad(windowConfig,windowName)))
        return 1;

    unsigned int flag = 0;

    sceneryLoad(0);

    musicLoad(0);
    for (int i = 0; i < 6; ++i)
    {
        textFont[i].font = fontArial;
    }
    
    sfMusic_setLoop(music.soundLong, sfTrue);
    sfMusic_play(music.soundLong);

    textLoad(win.window, 2);

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
                            sfText_setColor(textFont[0].text, colorPrimary);
                            sfText_setColor(textFont[2].text, colorSecondary);
                            flag = 0;
                            break;
                                
                        case sfKeyDown:
                            sfSound_play(music.soundShort2);
                            sfText_setColor(textFont[2].text, colorPrimary);
                            sfText_setColor(textFont[0].text, colorSecondary);
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
        
        /*sfFont_destroy(textFont.font);
        sfText_destroy(textFont[0].text);

        sfText_destroy(textFont[2].text);
        sfText_destroy(textFont[3].text);*/

        sfSprite_destroy(scenery.sprite);
        sfTexture_destroy(scenery.texture);

        sfRenderWindow_destroy(win.window);
        
    return 0;
}

void menuDraw(){
    sfRenderWindow_clear(win.window, colorTertiary);
    /**/
        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawText(win.window, textFont[0].text, NULL);
        sfRenderWindow_drawText(win.window, textFont[2].text, NULL);
        sfRenderWindow_drawText(win.window, textFont[3].text, NULL);
    /**/
    sfRenderWindow_display(win.window);    
}