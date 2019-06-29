#include "../include/assets.h"

typedef struct{

    sfRenderWindow* window;
    unsigned int x, y, pixel;
    char* title;   

}Window; 

Window win;

int WindowCreate(unsigned int, unsigned int, 
				 unsigned int, char*);
void WindowDraw();