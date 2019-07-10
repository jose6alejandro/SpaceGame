#include "player.h"
#include "enemy.h"
#include "scenery.h"
#include "text.h"
#include "time.h"

typedef struct{

    sfRenderWindow* window;
    sfEvent event;
    char* title; 
    unsigned int x,
    			 y, 
    			 pixel;
}Game; 

Game game;

int  gameWindow(unsigned int, unsigned int, 
				 unsigned int, char*);
int  gameStart();
void gameRun();
void gameEvents();
void gameDraw();
void gameGlobalBounds();
