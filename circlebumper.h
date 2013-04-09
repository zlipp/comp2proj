// Kevin Wern
// circlebumper.h--if hit, add score and light bumper
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "item.h"

class CircleBumper : public Item {

    private:
        int size,score;
        int islit;
        SDL_Surface* image;
        SDL_Surface* lit;

    public:
        CircleBumper(int Score, int Size, int xloc, int yloc); //find location
        char getClass(); //return info about self
        int getLocationx(); //return x location
        int getLocationy(); //return y location (for collision management)
        int hit();          //performs actions/mods to hit item, in this case, turning the light on or off
        int isLit();
        int getScore();    //gets score to add
        void draw(SDL_Surface *screen);  //polymorphic draw
    
};
