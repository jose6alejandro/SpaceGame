#include "../include/bullet.h"

void bulletLoad(sfSprite* playerSprite){
	bullet.texture = sfTexture_createFromFile("assets/laser.png", NULL);
	bullet.sprite = sfSprite_create();
	sfSprite_setTexture(bullet.sprite, bullet.texture, sfTrue);
	
	bulletConfig(sfSprite_getPosition(playerSprite).x, 
		sfSprite_getPosition(playerSprite).y, 0.4, 0.4, colorNone);

}

void bulletConfig(unsigned int  x, unsigned int y, 
					float  scaleX, float scaleY, sfColor color){

	bullet.vectorPosition.x = x;
	bullet.vectorPosition.y = y;
	sfSprite_setPosition(bullet.sprite, bullet.vectorPosition);

	bullet.vectorScale.x = 0.4;
	bullet.vectorScale.y = 0.4;
	sfSprite_scale(bullet.sprite, bullet.vectorScale);

	bullet.vectorOrigin.x = sfTexture_getSize(bullet.texture).x/2; 
	bullet.vectorOrigin.y = sfTexture_getSize(bullet.texture).y/2;
	sfSprite_setOrigin(bullet.sprite, bullet.vectorOrigin);

	sfSprite_setColor(bullet.sprite, color);	
}
void bulletMove(int x, int y){
    bullet.vectorPosition.x = x; 
    bullet.vectorPosition.y = y;    
    sfSprite_move(bullet.sprite, (bullet.vectorPosition));
}


