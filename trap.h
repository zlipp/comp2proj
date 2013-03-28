// Kevin Wern
// trap.h
// center "hole", ball is held and shot back if ball "falls" in
#include <iostream>
#include <SDL/SDL.h>

class Trap {

    private:
        int time,x,y,size;
        int istrapped;
        SDL_Surface* image;

    public:
        Trap(int Size, int xloc, int yloc); //find location
        int getClass(); //return info about self
        int getLocationx(); //return x location
        int getLocationy(); //return y location (for collision management)
        int adjust();  // decrement time if time is
        int hit();          //performs actions/mods to hit item if item collides
        int isTrapped();    //gets whether or not the ball is present
        void draw(SDL_Surface *screen);  //polymorphic draw
    
}
