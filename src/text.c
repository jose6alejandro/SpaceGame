#include "../include/text.h"

void textLoad(sfRenderWindow* window, int flag){
    textFont.font = fontArial;
    
    if(flag == 0){
        textFont.text = sfText_create();
        sfText_setString(textFont.text, "GAME OVER");
        sfText_setFont(textFont.text, textFont.font);
        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 50;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - 50;
        sfText_setPosition(textFont.text, textFont.vectorPosition);
       
        textFont.vectorOrigin.x = (float)sfText_getGlobalBounds(textFont.text).width/2; 
        textFont.vectorOrigin.y = (float)sfText_getGlobalBounds(textFont.text).height/2; 
        sfText_setOrigin(textFont.text,textFont.vectorOrigin);

        sfText_setCharacterSize(textFont.text, textSize - 40);
        sfText_setColor(textFont.text, colorSecondary);        
    
    }else{
        textFont.text2 = sfText_create();
        sfText_setCharacterSize(textFont.text2, textSize - 50);
        sfText_setFont(textFont.text2, textFont.font);
        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x - 770;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y - 600;
        sfText_setPosition(textFont.text2, textFont.vectorPosition);
        sfText_setColor(textFont.text2, colorSecondary);
    }

}

void textMenuLoad(sfRenderWindow* window){

        textFont.font = fontArial;
        textFont.text = sfText_create();
        sfText_setString(textFont.text, "Start");
        sfText_setFont(textFont.text, textFont.font);
        sfText_setCharacterSize(textFont.text, textSize - 20);

        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 80;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - 100;
        sfText_setPosition(textFont.text, textFont.vectorPosition);
        sfText_setColor(textFont.text, colorPrimary);
        
        textFont.text2 = sfText_create();
        sfText_setString(textFont.text2, "Quit");
        sfText_setFont(textFont.text2, textFont.font);
        sfText_setCharacterSize(textFont.text2, textSize - 20);
        
        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 60;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2;
        sfText_setPosition(textFont.text2, textFont.vectorPosition);
        sfText_setColor(textFont.text2, colorSecondary);

        textFont.text3 = sfText_create();
        sfText_setString(textFont.text3, "Space defense");
        sfText_setFont(textFont.text3, textFont.font);
        sfText_setCharacterSize(textFont.text3, textSize - 20);

        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 210;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y - 550;
        sfText_setPosition(textFont.text3, textFont.vectorPosition);
        sfText_setColor(textFont.text3, colorPrimary);
}

