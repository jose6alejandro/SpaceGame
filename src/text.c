#include "../include/text.h"


void textLoad(sfRenderWindow* window, unsigned int flag){
    
    if(flag == 0){
        textFont[0].text = sfText_create();
        textConfig(0, window,textFont[0].text,"GAME OVER", 0, 0, colorSecondary,60);
       
        textFont[1].text = sfText_create();
        textConfig(1, window,textFont[1].text,"Press [Esc]", -310, -220, colorSecondary, 40);
   
    }else if(flag == 1){
        textFont[2].text = sfText_create();  
        textConfig(2, window,textFont[2].text,"Time "/*seg*/, -120, 280, colorSecondary, 40);

        textFont[3].text = sfText_create();  
        textConfig(3 ,window,textFont[3].text,"Level 1", -300, 280, colorSecondary, 40);
        
        textFont[4].text = sfText_create();  
        textConfig(4, window,textFont[4].text,"Nave x 1", 290, 280, colorSecondary, 40);    

        textFont[5].text = sfText_create();
        textConfig(5, window,textFont[5].text,"Score 0", 90, 280, colorSecondary, 40);
    
    }else{
        textFont[0].text = sfText_create();
        textConfig(0, window,textFont[0].text,"Start", 0, 70, colorPrimary, 80);
        
        textFont[2].text = sfText_create();
        textConfig(2, window,textFont[2].text,"Quit", -0, -30, colorSecondary, 80);

        textFont[3].text = sfText_create();
        textConfig(3,window,textFont[3].text,"Space defense", 0, 210, colorPrimary, 80);
    }
}

/*
    textConfig(position array, window, sfText, string, cord X, cord Y, color, text size);
*/

void textConfig(unsigned int i, sfRenderWindow* window, sfText* text,
                const char* string, unsigned int  x,
                unsigned int y, sfColor color,  unsigned int size){
    
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, textFont[i].font);

    textFont[i].vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - x;
    textFont[i].vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - y;
    sfText_setPosition(text, textFont[i].vectorPosition);

    textFont[i].vectorOrigin.x = (float)sfText_getGlobalBounds(textFont[i].text).width/2; 
    textFont[i].vectorOrigin.y = (float)sfText_getGlobalBounds(textFont[i].text).height/2; 
    sfText_setOrigin(text,textFont[i].vectorOrigin);
    sfText_setColor(text, color);   
}
