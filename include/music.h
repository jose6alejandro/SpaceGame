#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct{

    sfMusic* soundLong;
    sfSound* soundShort;
    sfSound* soundShort2;
    sfSoundBuffer* soundBuffer;
    sfSoundBuffer* soundBuffer2;

}Music;

Music music;

void musicMenu();
void musicCleanMenu();