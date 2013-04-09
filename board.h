#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <vector>
#include "ball.h"
#include "item.h"
using namespace std;

#ifndef BOARD_H
#define BOARD_H
class Board {

    private:
        vector<Item*> items;
        Ball ball;
        int x,y;
        int score;
        int turns;
        SDL_Surface *screen;
        SDL_Event event;
        //Flipper flip;
    public:
        Board(int x,int y,SDL_Surface *scr);
        void play();
        void add(Item *i);
        void draw();
        void move();
        void evaluate();

};

#endif
