#include <iostream>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#ifndef BALL_H
#define BALL_H
class Ball {
    private:
        int x,y,xv,yv;
        SDL_Surface *image;
    public:
        Ball();
        void draw(SDL_Surface *s);
        void move();
};
#endif
