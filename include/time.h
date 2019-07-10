#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfClock* clock;
    sfTime time;
    int time2;

}Time;

Time timeUp;

void timeLoad();
