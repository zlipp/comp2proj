#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "circlebumper.h"
#include <iostream>
using namespace std;


CircleBumper::CircleBumper(int Score,int Size, int xloc, int yloc) {
    x = xloc;
    y = yloc;
    islit = 0;
    SDL_Surface* loaded = IMG_Load("bumperoff.bmp");
    if (loaded == NULL) { cout << "well shit then"<<endl;}
    image = SDL_DisplayFormat(loaded);
    if (image == NULL) cout<< "double shit" << endl;
}

char CircleBumper::getClass(){
    return 'b';
}

void CircleBumper::draw(SDL_Surface *screen){
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(image, NULL, screen, &offset);
}
