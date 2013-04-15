/* Zach Lipp 3/27/13
Splash Screen 
*/
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <deque>
#include "button.h"
#include "textBox.h"
using namespace std;

class splashScreen
{
 public:
  splashScreen();//default constructor, loads splashScreen.bmp then is pointed to by image
  int display(SDL_Surface *); //displays the splash screen on the screen passed in, returns 0 if success, sets selection
  void setNames(deque<string> *); //points to high scorers
  void setScores(deque<int> *);//points to high scores
  void blitHighScores(SDL_Surface *); //blits high scores to screen
  int getSelection(); //returns the selection
  ~splashScreen();

 private:
  int wait();//return 0 when a button is pressed, 1 when else where is clicked
  SDL_Surface *bg; 
  deque<string> *names;//points to names for high score board
  deque<int> *scores;//points to scores for high score board
  //initializes all necessary buttons and textBox
  textBox pinball;
  button play;
  button quit;
  button instruct;
  textBox highScore;
  int selection; //1 for play, 2 for instructions, 3 for quit
  };

#endif
