#include "../include/scenery.h"

void sceneryLoad(){

	scenery.texture = sfTexture_createFromFile("assets/space.png", NULL);
	scenery.sprite = sfSprite_create();

	sfSprite_setTexture(scenery.sprite, scenery.texture, sfTrue);	
}