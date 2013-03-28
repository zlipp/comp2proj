#include <iostream>
#include <SDL/SDL_image.h>
class Ball {
    private:
        int x,y,xv,yv;
        SDL_Surface *image;
    public:
        Ball();
        void draw(SDL_Surface *s);
        void move();
};
