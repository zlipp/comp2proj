/* Zach Lipp 4/15/13

This is the header file for the instructions object.
*/
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "button.h"
#include "textBox.h"
#include <iostream>
#include <string>
#include <SDL/SDL.h>
using namespace std;

class instructions
{
 public:
  instructions();//default constructor 
  int display(SDL_Surface *screen); //displays image to screen, return 0 when success
  ~instructions();

 private:
  SDL_Surface *image; //points to instructions screen
  button back;
  int wait();
};

#endif
