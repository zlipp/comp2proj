#include "board.h"
#include "ball.h"
#include "item.h"
#include "circlebumper.h"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
using namespace std;

Board::Board(int xpos, int ypos, SDL_Surface *scr){
//    SDL_Init(SDL_INIT_EVERYTHING);
    screen = scr;
    x = xpos;
    y = ypos;
    score = 0;
    turns = 3;
    CircleBumper* c1 = new CircleBumper(200,5,100,100);
    CircleBumper* c2 = new CircleBumper(200,5,200,100);
    CircleBumper* c3 = new CircleBumper(200,5,300,100);
    add(c1);
    add(c2);
    add(c3);
}

void Board::play() {
    
    while (1){
        if (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    exit(0);
            }
        }
        SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );
        ball.draw(screen);
        draw();
        SDL_Flip(screen);
        SDL_Delay(10);
        ball.move();

    }
}

void Board::add(Item *i){
    items.push_back(i);
}

void Board::draw(){
    int i;
    for (i = 0; i<items.size();++i){
        items[i]->draw(screen);
    }
}
