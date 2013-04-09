#include <SDL/SDL.h>
#ifndef ITEM_H
#define ITEM_H

class Item {
    protected:
        int x,y;
    public:
        int getLocationX();
        int getLocationY();
        virtual void draw(SDL_Surface *screen) = 0;
        char getClass();
};
#endif
