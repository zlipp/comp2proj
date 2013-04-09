#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL/SDL.h>
#include "textBox.h"
#include <string>
using namespace std;

//inherits from textBox
class button : public textBox
{
 public: 
  button(); //default constructor needed for composition
  button(string, string, int size, int xPos, int yPos);//creates button with text string of size size  at xPos, yPos
  int blit(SDL_Surface *screen); // blits image to s
  void center(int c);//centers text box at x=c
  int mouseOn(); //returns 1 if pressed cursor is over button, otherwise returns 0
  //needed for = operator
  int getX();
  int getY();
  
  //  text getT();
  void operator=(button);

 private:
  int x,y; //position of button
  
  //needed for = operator
  void setX(int);
  void setY(int);
};

#endif
 
