#include "player.h"
#include "scenery.h"

typedef struct{

    sfRenderWindow* window;
    sfEvent event;
    unsigned int x, y, pixel;
    char* title;   

}Game; 

Game game;

int gameWindow(unsigned int, unsigned int, 
				 unsigned int, char*);
int gameStart();
void gameRun();
void gameEvents();
void gameDraw();