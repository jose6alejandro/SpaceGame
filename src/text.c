#include "../include/text.h"

void textGameOver(){

    textFont.font = sfFont_createFromFile("assets/arial.ttf");
    textFont.text = sfText_create();
    sfText_setString(textFont.text, "GAME OVER");
    sfText_setFont(textFont.text, textFont.font);
    sfText_setCharacterSize(textFont.text, textSize);
}

void textTime(sfRenderWindow* window){
    textFont.font2 = sfFont_createFromFile("assets/arial.ttf");
    textFont.text2 = sfText_create();
    sfText_setCharacterSize(textFont.text2, textSize - 50);
    sfText_setFont(textFont.text2, textFont.font2);
    textFont.vectorPosition.x = sfRenderWindow_getSize(window).x - textSize - 780;
    textFont.vectorPosition.y = sfRenderWindow_getSize(window).y - textSize - 700;
    sfText_setPosition(textFont.text2, textFont.vectorPosition);
}