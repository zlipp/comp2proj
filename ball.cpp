#include "ball.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
using namespace std;

Ball::Ball(){
    x = 0;
    y = 0;
    xv = 3, yv = 5;
    SDL_Surface* loaded = IMG_Load("ball.bmp");
    if (loaded == NULL) cout << "well shit"<<endl;
    image = SDL_DisplayFormat(loaded);
    if (image == NULL) cout<< "double shit" << endl;
}

void Ball::move() {
    x += xv;
    y += yv;
    if (x>500 || x<0) xv = -xv;
    if (y>500 || y<0) yv = -yv;
}

void Ball::draw(SDL_Surface* screen){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image, NULL, screen, &offset);
//    SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0x0 ) );
}

