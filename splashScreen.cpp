/* Zach Lipp 3/27/13
Splash Screen

referenced gpwiki.org and lazyFoo.org for SDL syntax
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include "splashScreen.h"
#include "button.h"
#include "textBox.h"
#include <vector>
#include <sstream>
using namespace std;

//splash screen constructor
splashScreen::splashScreen()
{
  //sets up bg 
  SDL_Surface *temp; 
  temp = IMG_Load("background.bmp");
  if(temp == NULL) 
    {
      cout<<"Unable to load splashScreen.bmp"<<endl;
      return;//returns if file unable to load
    }
  bg = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  //sets buttons
  play= button("Play", "lazy.ttf", 28, 150, 100);
  instruct= button("Instructions", "lazy.ttf", 28, 150, 150);
  quit = button("Quit", "lazy.ttf", 28, 150,200);

  //center buttons on mid line x = 320
  play.center(320);
  instruct.center(320);
  quit.center(320);

  //blits buttons onto splashscreen
  play.blit(bg);
  instruct.blit(bg);
  quit.blit(bg);

  //creates textBox
  highScore = textBox("High Scores", "lazy.ttf", 28);
  pinball = textBox("PINBALL", "lazy.ttf", 40);

  //blits textBox to screen centered at x=320
  highScore.blitC(bg, 320, 250);
  pinball.blitC(bg, 320, 20);
};

//returns 0 if successful
//displays splashScreen
int splashScreen::display(SDL_Surface *screen)
{
  if(bg==NULL)
    {
      cout<<"Background pointer has not initialized"<<endl;
      return 1;
    }
  if(screen==NULL)
    {
      cout<<"Null pointer passed as parameter"<<endl;
      return 1;
    }

  //adds high scores to bg
  blitHighScores();
  SDL_BlitSurface(bg, NULL, screen, NULL);

  SDL_Flip(screen);
 
  while(wait())  //waits until button is clicked
    SDL_Delay(100);//waits .1 secs to allow reset

  return 0;
}

//waits for user to click 
//returns 0 when they click a button and 1 when they click elsewhere
int splashScreen::wait()
{
  SDL_PumpEvents();//need one pre while loop

  while( !(SDL_GetMouseState(NULL,NULL) == SDL_BUTTON_LEFT) ) //Stays in loop until left mouse button pressed
    SDL_PumpEvents(); //Pumps input through

  //play pressed
  if(play.mouseOn()) 
    {
      cout<<"Play was pressed!!"<<endl;
      return 0;
    }

  //instructions pressed
  if(instruct.mouseOn())
    {
      cout<<"Instructions was pressed!!"<<endl;
      return 0;
    }

  //Quit pressed
  if(quit.mouseOn())
    {
      cout<<"Quit was pressed :("<<endl;
      return 0;
    }
    
  return 1;
}

//set the names to point to highscore names
void splashScreen::setNames(vector<string> *n)
{
  names=n;
}

//set scores to point to vecto rof high scores
void splashScreen::setScores(vector<int> *s)
{
  scores = s;
}

void splashScreen::blitHighScores()
{
  int max;//finds the numbered of name and score pairs
  if(names->size() < scores->size() )
    max= names->size();
  else
    max= scores->size();

  int y=300; //top of high score table
  //displays each entry one under the other
  for(int i = 0; i<max; i++)
    { 
      stringstream ss;
      ss<<i+1<<"\t"<<(*names)[i]<<"\t"<<(*scores)[i];
      string str = ss.str();
      textBox HS(str,"lazy.ttf",28);
      HS.blit(bg, 250, y);
      y+=HS.getHeight()+10;
    }
}


splashScreen::~splashScreen()
{
  SDL_FreeSurface(bg);
}
