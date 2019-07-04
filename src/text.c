#include "../include/text.h"

void textGameOver(){

    textFont.font = sfFont_createFromFile("assets/arial.ttf");
    textFont.text = sfText_create();
    sfText_setString(textFont.text, "GAME OVER");
    sfText_setFont(textFont.text, textFont.font);
    sfText_setCharacterSize(textFont.text, textSize);
}