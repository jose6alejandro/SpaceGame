#include "../include/music.h"

void musicMenu(){
    music.soundLong = sfMusic_createFromFile("music/space.ogg");
    music.soundShort = sfSound_create();
    music.soundBuffer = sfSoundBuffer_createFromFile("music/up.ogg");
    music.soundShort2 = sfSound_create();
    music.soundBuffer2 = sfSoundBuffer_createFromFile("music/down.ogg");    
    sfSound_setBuffer(music.soundShort, music.soundBuffer);
    sfSound_setBuffer(music.soundShort2, music.soundBuffer2);
}

void musicCleanMenu(){
    sfMusic_destroy(music.soundLong); 
    sfSound_destroy(music.soundShort);
    sfSound_destroy(music.soundShort2);
    sfSoundBuffer_destroy(music.soundBuffer);
    sfSoundBuffer_destroy(music.soundBuffer2);
}