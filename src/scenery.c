#include "../include/scenery.h"

void sceneryLoad(int scene){
	
	if(scene == 1)
		scenery.texture = sfTexture_createFromFile("assets/space.png", NULL);
	else
		scenery.texture = sfTexture_createFromFile("assets/space2.png", NULL);

	scenery.sprite = sfSprite_create();
	sfSprite_setTexture(scenery.sprite, scenery.texture, sfTrue);	
}