
/* Zach Lipp 3/27/13
Splash Screen 
*/
#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
#include "button.h"
#include "textBox.h"
using namespace std;

class splashScreen
{
 public:
  splashScreen();//default constructor, loads splashScreen.bmp then is pointed to by image
  int display(SDL_Surface *); //displays the splash screen on the screen passed in
  void setNames(vector<string> *);
  void setScores(vector<int> *);
  void blitHighScores();
  ~splashScreen();

 private:
  int wait();
  SDL_Surface *bg; 
  vector<string> *names;//points to names for high score board
  vector<int> *scores;//points to scores for high score board
  //initializes all necessary buttons and textBox
  textBox pinball;
  button play;
  button quit;
  button instruct;
  textBox highScore;
  };

#endif
