#include "../include/bullet.h"

void bulletLoad(sfSprite* playerSprite){
	bullet.texture = sfTexture_createFromFile("assets/laser.png", NULL);
	bullet.sprite = sfSprite_create();
	sfSprite_setTexture(bullet.sprite, bullet.texture, sfTrue);

	bullet.vectorScale.x = 0.4;
	bullet.vectorScale.y = 0.4;
	sfSprite_scale(bullet.sprite, bullet.vectorScale);

	bullet.vectorOrigin.x = sfTexture_getSize(bullet.texture).x/2; 
	bullet.vectorOrigin.y = sfTexture_getSize(bullet.texture).y/2;
	sfSprite_setOrigin(bullet.sprite, bullet.vectorOrigin);

	bullet.vectorPosition.x = sfSprite_getPosition(playerSprite).x;
	bullet.vectorPosition.y = sfSprite_getPosition(playerSprite).y;
	sfSprite_setPosition(bullet.sprite, bullet.vectorPosition);
	
	/*bullet.clock = sfClock_create();
	
	bullet.velocity.x = 20;
	bullet.velocity.y = -20;

	bullet.accelerate.x = 0;
	bullet.accelerate.y = 0;*/
}
void bulletMove(int x, int y){
    bullet.vectorPosition.x = x; 
    bullet.vectorPosition.y = y;    
    sfSprite_move(bullet.sprite, (bullet.vectorPosition));
}
/*
void bulletUpdate(sfSprite* playerSprite){
	
	bullet.time2 = (int)sfTime_asSeconds(bullet.time) / 10;
	bullet.velocity.x = bullet.accelerate.x * bullet.time2;
	bullet.velocity.y = bullet.accelerate.y * bullet.time2;

	bullet.vectorPosition.x = sfSprite_getPosition(playerSprite).x + bullet.velocity.x * bullet.time2;
	bullet.vectorPosition.y = sfSprite_getPosition(playerSprite).y + bullet.velocity.y * bullet.time2;

	sfSprite_setPosition(bullet.sprite, bullet.vectorPosition);
	
}*/

