#include "../include/text.h"

void textLoad(sfRenderWindow* window, unsigned int flag){
    textFont.font = fontArial;
    
    if(flag == 0){
       textFont.text = sfText_create();
        textConfig(window,textFont.text,"GAME OVER", 0, 0, colorSecondary,60);
    
    }else if(flag == 1){
        textFont.text2 = sfText_create();  
        textConfig(window,textFont.text2,"Time ", -60, 280, colorSecondary, 40);
    }else if(flag == 2){
        textFont.text3 = sfText_create();  
        textConfig(window,textFont.text3,"Level 1", -360, 280, colorSecondary, 40);
    }else if(flag == 3){
        textFont.text4 = sfText_create();  
        textConfig(window,textFont.text4,"Nave x -", 260, 280, colorSecondary, 40);
    }else{
        textMenuLoad(window);
    }
}

void textMenuLoad(sfRenderWindow* window){

        textFont.font = fontArial;

        textFont.text = sfText_create();
        textConfig(window,textFont.text,"Start", 0, 70, colorPrimary, 80);
        
        textFont.text2 = sfText_create();
        textConfig(window,textFont.text2,"Quit", -20, -30, colorSecondary, 80);

        textFont.text3 = sfText_create();
        textConfig(window,textFont.text3,"Space defense", 130, 210, colorPrimary, 80);

}

void textConfig(sfRenderWindow* window, sfText* text,
                const char* string, unsigned int  x,
                unsigned int y, sfColor color,  unsigned int size){
    
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, textFont.font);

    textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - x;
    textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - y;
    sfText_setPosition(text, textFont.vectorPosition);

    textFont.vectorOrigin.x = (float)sfText_getGlobalBounds(textFont.text).width/2; 
    textFont.vectorOrigin.y = (float)sfText_getGlobalBounds(textFont.text).height/2; 
    sfText_setOrigin(text,textFont.vectorOrigin);
    sfText_setColor(text, color);   
}
