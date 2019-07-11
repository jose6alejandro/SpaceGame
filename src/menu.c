#include "../include/menu.h"

int menuExecute(){

        if (!(windowLoad(900, 800, 32, "SpaceGame")))
        return 1;

    unsigned int flag = 0;

    textFont.font = sfFont_createFromFile("assets/arial.ttf");
    
    sceneryLoad(0);

    textMenu(win.window);

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
                            sfText_setColor(textFont.text, sfColor_fromRGBA(252,246,53,125));
                            sfText_setColor(textFont.text2, sfColor_fromRGBA(224,224,219,200));
                            flag = 0;
                            break;
                                
                        case sfKeyDown:
                            sfText_setColor(textFont.text2, sfColor_fromRGBA(252,246,53,125));
                            sfText_setColor(textFont.text, sfColor_fromRGBA(224,224,219,200));
                            flag = 1;
                            break; 

                        case sfKeyReturn:
                        case sfKeySpace:
                                
                            if(!flag == 0){
                                sfRenderWindow_close(win.window);
                            }
                            else{
                                sfRenderWindow_close(win.window);
                                return gameStart();
                            }   
                            break;   
                    }
            }
        }

        menuDraw();   
    }
  
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
    sfRenderWindow_clear(win.window, sfColor_fromRGB(57, 161, 92));
    /**/
        sfRenderWindow_drawSprite(win.window, scenery.sprite, NULL); 
        sfRenderWindow_drawText(win.window, textFont.text, NULL);
        sfRenderWindow_drawText(win.window, textFont.text2, NULL);
        sfRenderWindow_drawText(win.window, textFont.text3, NULL);
    /**/
    sfRenderWindow_display(win.window);    
}