#include "../include/enemy.h"

void enemyLoad(){

	int enemyRand = enemyNum();

	char enemyName[tam] = "assets/meteor";
	char enemyExe [tam] = ".png";
	char enemyAux [tam];

	sprintf(enemyAux,"%i",enemyRand);

	strcat( enemyName, enemyAux);
	strcat( enemyName, enemyExe);

	enemy.texture = sfTexture_createFromFile(enemyName, NULL);
	enemy.sprite = sfSprite_create();
	sfSprite_setTexture(enemy.sprite, enemy.texture, sfTrue);

	enemy.vectorPosition.x = 400;
	enemy.vectorPosition.y = 40;
	sfSprite_setPosition(enemy.sprite, enemy.vectorPosition);

	enemy.vectorOrigin.x = sfTexture_getSize(enemy.texture).x/2; 
	enemy.vectorOrigin.y = sfTexture_getSize(enemy.texture).y/2;
	sfSprite_setOrigin(enemy.sprite, enemy.vectorOrigin);	
}

int enemyNum(){
	srand(time(NULL)); 
	int enemyRand = rand() % 4 + 1;
	return 	enemyRand;
}