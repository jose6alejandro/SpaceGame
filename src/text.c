#include "../include/text.h"

unsigned int textFontLoad(int i){
    
    if(i < 0)
        return 0;

    textFont[i].font = fontArial; 

        if (i == 0 || i == 1) 
            textLoad(i); 

    return textFontLoad(i - 1);
}

void textLoad(unsigned int flag){
    
    if(flag == 0){
        textFont[0].text = sfText_create();
        textConfig(0, textFont[0].text,"GAME OVER", 0, 0, colorSecondary,60);
       
        textFont[1].text = sfText_create();
        textConfig(1, textFont[1].text,"Press [Esc]", -270, -220, colorSecondary, 40);
   
    }else if(flag == 1){
        textFont[2].text = sfText_create();  
        textConfig(2, textFont[2].text,"Time "/*seg*/, -120, 280, colorSecondary, 40);

        textFont[3].text = sfText_create();  
        textConfig(3, textFont[3].text,"Level 1", -300, 280, colorSecondary, 40);
        
        textFont[4].text = sfText_create();  
        textConfig(4, textFont[4].text,"Nave x 3"/*x 3*/, 290, 280, colorSecondary, 40);    

        textFont[5].text = sfText_create();
        textConfig(5, textFont[5].text,"Score 0"/*0*/, 90, 280, colorSecondary, 40);
    
    }else{
        textFont[0].text = sfText_create();
        textConfig(0, textFont[0].text,"Start", 0, 70, colorPrimary, 80);
        
        textFont[2].text = sfText_create();
        textConfig(2, textFont[2].text,"Quit", -0, -30, colorSecondary, 80);

        textFont[3].text = sfText_create();
        textConfig(3, textFont[3].text,"Space defense", 0, 210, colorPrimary, 80);
    }
}

/*
    textConfig(position array, sfText, string, cord X, cord Y, color, text size);
*/
void textConfig(unsigned int i, sfText* text, 
                const char* string, unsigned int  x,
                unsigned int y, sfColor color,  unsigned int size){
    
    sfText_setString(text, string);
    sfText_setCharacterSize(text, size);
    sfText_setFont(text, textFont[i].font);

    textFont[i].vectorPosition.x = sfRenderWindow_getSize(win.window).x / 2 - x;
    textFont[i].vectorPosition.y = sfRenderWindow_getSize(win.window).y / 2 - y;
    sfText_setPosition(text, textFont[i].vectorPosition);

    textFont[i].vectorOrigin.x = (float)sfText_getGlobalBounds(textFont[i].text).width/2; 
    textFont[i].vectorOrigin.y = (float)sfText_getGlobalBounds(textFont[i].text).height/2; 
    sfText_setOrigin(text,textFont[i].vectorOrigin);
    sfText_setColor(text, color);   
}
