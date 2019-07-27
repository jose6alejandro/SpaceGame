#include "../include/enemy.h"

void enemyLoad(int i){

	if (i < tam*2){
	    char enemyName[tam] = "assets/meteor";
	    char enemyExe [tam] = ".png";
	    char enemyAux [tam];

	    sprintf(enemyAux,"%i",rand() % 4 + 1);
	    strcat( enemyName, enemyAux);
	    strcat( enemyName, enemyExe);

	    enemy[i].texture = sfTexture_createFromFile(enemyName, NULL);
	    enemy[i].sprite = sfSprite_create();
	    //sfSprite_setTexture(enemys[i].sprite, enemys[i].texture, sfTrue);

	 	enemyLoad(i + 1);
 	}
}
void enemyDestroy(int i){

	if (i < tam*2){
        if((enemy[i].sprite != NULL) && (enemy[i].texture != NULL)){
            sfSprite_destroy(enemy[i].sprite);
            sfTexture_destroy(enemy[i].texture);
        }
        enemyDestroy(i + 1);
	}

}

