#include "../include/text.h"

void textGameOver(sfRenderWindow* window){
    textFont.text = sfText_create();
    sfText_setString(textFont.text, "GAME OVER");
    sfText_setFont(textFont.text, textFont.font);
    textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - textSize * 100 / 50;
    textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - textSize * 100 / 200;
    sfText_setPosition(textFont.text, textFont.vectorPosition);
    sfText_setCharacterSize(textFont.text, textSize);
}

void textTime(sfRenderWindow* window){
    textFont.text2 = sfText_create();
    sfText_setCharacterSize(textFont.text2, textSize - 50);
    sfText_setFont(textFont.text2, textFont.font);
    textFont.vectorPosition.x = sfRenderWindow_getSize(window).x - textSize - 780;
    textFont.vectorPosition.y = sfRenderWindow_getSize(window).y - textSize - 700;
    sfText_setPosition(textFont.text2, textFont.vectorPosition);
}

void textMenu(sfRenderWindow* window){
        textFont.text = sfText_create();
        sfText_setString(textFont.text, "Start");
        sfText_setFont(textFont.text, textFont.font);
        sfText_setCharacterSize(textFont.text, textSize - 10);

        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 80;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2 - textSize;
        sfText_setPosition(textFont.text, textFont.vectorPosition);
        
        sfText_setColor(textFont.text, sfColor_fromRGBA(252,246,53,125));
        
        textFont.text2 = sfText_create();
        sfText_setString(textFont.text2, "Quit");
        sfText_setFont(textFont.text2, textFont.font);
        sfText_setCharacterSize(textFont.text2, textSize - 10);
        
        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 60;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y / 2;
        sfText_setPosition(textFont.text2, textFont.vectorPosition);

        sfText_setColor(textFont.text2, sfColor_fromRGBA(224,224,219,200));

        textFont.text3 = sfText_create();
        sfText_setString(textFont.text3, "Space defense");
        sfText_setFont(textFont.text3, textFont.font);
        sfText_setCharacterSize(textFont.text3, textSize - 10);

        textFont.vectorPosition.x = sfRenderWindow_getSize(window).x / 2 - 230;
        textFont.vectorPosition.y = sfRenderWindow_getSize(window).y - 700;
        sfText_setPosition(textFont.text3, textFont.vectorPosition);

        sfText_setColor(textFont.text3, sfColor_fromRGBA(252,246,53,125));
}