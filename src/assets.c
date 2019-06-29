#include "../include/assets.h"

/*
	Crear texturas y sprites
*/
void assetsCreate(){
	
	resource.texture = sfTexture_createFromFile("assets/nave.png", NULL);
	resource.texture2 = sfTexture_createFromFile("assets/space.png", NULL);
	resource.sprite = sfSprite_create();
	resource.sprite2 = sfSprite_create();
	sfSprite_setTexture(resource.sprite, resource.texture, sfTrue);
	sfSprite_setTexture(resource.sprite2, resource.texture2, sfTrue);
}

/*
	Cargar y modificar texturas y/o sprites
*/
void assetsLoad(Sprite edit){

	assetsCreate();

	edit.vectorPosition.x = 450;
	edit.vectorPosition.y = 400;
	sfSprite_setPosition(resource.sprite, edit.vectorPosition);
	    
	edit.vectorScale.x = 0.4;
	edit.vectorScale.y = 0.4;
	//sfSprite_setScale(resource.sprite, vectorScale);
	sfSprite_scale(resource.sprite, edit.vectorScale);

	edit.vectorOrigin.x = sfTexture_getSize(resource.texture).x/2; 
	edit.vectorOrigin.y = sfTexture_getSize(resource.texture).y/2;
	sfSprite_setOrigin(resource.sprite, edit.vectorOrigin);
	
	//sfSprite_setRotation(resource.sprite, 10);
	sfSprite_setColor(resource.sprite, sfColor_fromRGBA(250, 250, 250, 250));
}
