#include "../include/player.h"
#include "../include/music.h"

void playerLoad(){

	player.texture = sfTexture_createFromFile("assets/nave.png", NULL);
	player.sprite = sfSprite_create();
	sfSprite_setTexture(player.sprite, player.texture, sfTrue);

	playerConfig(400, 500, 0.3, 0.3, colorNone);
}

void playerMove(int x, int y){
    player.vectorPosition.x = x; 
    player.vectorPosition.y = y;    
    sfSprite_move(player.sprite, (player.vectorPosition));
}

void playerhandleInput(){
	if(sfKeyboard_isKeyPressed(sfKeyUp) || sfKeyboard_isKeyPressed(sfKeyW))
        playerMove(0, -2);

    if(sfKeyboard_isKeyPressed(sfKeyDown) || sfKeyboard_isKeyPressed(sfKeyS))
        playerMove(0, 2);

    if(sfKeyboard_isKeyPressed(sfKeyLeft) || sfKeyboard_isKeyPressed(sfKeyA))
        playerMove(-2, 0);

    if(sfKeyboard_isKeyPressed(sfKeyRight) || sfKeyboard_isKeyPressed(sfKeyD))
        playerMove(2, 0);

   	if(sfKeyboard_isKeyPressed(sfKeySpace)){
		bulletLoad(player.sprite);
		sfSound_setVolume(music.soundShort, 120);
		sfSound_play(music.soundShort);
	}

}
/*
    playerConfig(cord X, cord Y, scale X, scale Y, color);
*/
void playerConfig(unsigned int  x, unsigned int y, 
					float  scaleX, float scaleY, sfColor color){

	player.vectorPosition.x = x;
	player.vectorPosition.y = y;
	sfSprite_setPosition(player.sprite, player.vectorPosition);

	player.vectorScale.x = scaleX;
	player.vectorScale.y = scaleY;
	sfSprite_scale(player.sprite, player.vectorScale);

	player.vectorOrigin.x = sfTexture_getSize(player.texture).x/2; 
	player.vectorOrigin.y = sfTexture_getSize(player.texture).y/2;
	sfSprite_setOrigin(player.sprite, player.vectorOrigin);

	sfSprite_setColor(player.sprite, color);	
}
