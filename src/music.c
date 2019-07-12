#include "../include/music.h"

void musicLoad(int flag){
    if(flag == 0){
        music.soundLong = sfMusic_createFromFile("music/space.ogg");
        music.soundShort = sfSound_create();
        music.soundBuffer = sfSoundBuffer_createFromFile("music/up.ogg");
        music.soundShort2 = sfSound_create();
        music.soundBuffer2 = sfSoundBuffer_createFromFile("music/down.ogg");    
        sfSound_setBuffer(music.soundShort, music.soundBuffer);
        sfSound_setBuffer(music.soundShort2, music.soundBuffer2);       
    
    }else{
        music.soundBuffer = sfSoundBuffer_createFromFile("music/laser.ogg");
        music.soundShort = sfSound_create();
        sfSound_setBuffer(music.soundShort, music.soundBuffer);        
    }
}

void musicClean(int flag){

    sfSound_destroy(music.soundShort);
    sfSoundBuffer_destroy(music.soundBuffer);
   
    if(flag == 0){
        sfMusic_destroy(music.soundLong); 
        sfSound_destroy(music.soundShort2);
        sfSoundBuffer_destroy(music.soundBuffer2);       
    }
}
