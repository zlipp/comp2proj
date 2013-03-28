// Kevin Wern
// bonuslight.h -- when crossed, lights up.  A multiplier is in effect until it is crossed again and unlit
#include <iostream>
#include <SDL/SDL.h>

class BonusLight {

    private:
        int multiplier,x,y,size;
        int islit;
        SDL_Surface* image;
        SDL_Surface* lit;

    public:
        BonusLight(int Score, int Size, int xloc, int yloc); //find location
        int getClass(); //return info about self
        int getLocationx(); //return x location
        int getLocationy(); //return y location (for collision management)
        int hit();          //performs actions/mods to hit item, in this case, turning the light on or off
        int getMultiplier();    //gets score to add
        void draw(SDL_Surface *screen);  //polymorphic draw
    
}
