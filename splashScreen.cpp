/* Zach Lipp 3/27/13
Splash Screen

referenced gpwiki.org for SDL syntax
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include "splashScreen.h"
using namespace std;

//splash screen constructor
splashScreen::splashScreen()
{
  //sets up image  
  SDL_Surface *temp;
  temp = IMG_Load("splashScreen.bmp");
  if(temp == NULL) 
    {
      cout<<"Unable to load splashScreen.bmp"<<endl;
      return;//returns if file unable to load
    }
  image = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);
};

//returns 0 if successful
//displays splashScreen
int splashScreen::display(SDL_Surface *screen)
{
  if(image==NULL)
    {
      cout<<"splashScreen not initialized"<<endl;
      return 1;
    }
  if(screen==NULL)
    {
      cout<<"Null pointer passed as parameter"<<endl;
      return 1;
    }
  SDL_BlitSurface(image, NULL, screen, NULL);

  SDL_Flip(screen);
  return 0;
}

splashScreen::~splashScreen()
{
  SDL_FreeSurface(image);
}
