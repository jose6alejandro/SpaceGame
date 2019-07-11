#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfRenderWindow* window;
    sfEvent event;
    char* title; 
    unsigned int x,
    			 y, 
    			 pixel;
}Window; 

Window win;

int  windowLoad(unsigned int, unsigned int, 
				 unsigned int, char*);