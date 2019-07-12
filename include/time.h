#ifndef _TIMEUP_H
#define _TIMEUP_H


#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfClock* clock;
    sfTime time;
    //int time2;

}Time;

Time timeUp;

void timeLoad();

#endif //_TIMEUP_H