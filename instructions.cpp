/* Zach Lipp 4/15/13
Implementation of instruction class. Creates and displays instruction screen
*/

#include "button.h"
#include "textBox.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include "instructions.h"
using namespace std;

instructions::instructions()
{
  SDL_Surface *temp;
  temp = IMG_Load("background.bmp");
  if(temp == NULL)
    {
      cout<<"Unable to load background.bmp in instructions"<<endl;
      return;
    }

  image = SDL_DisplayFormat(temp);
  SDL_FreeSurface(temp);

  int y = 25;
  textBox t1("Instructions", "lazy.ttf", 40);
  t1.blitC(image, 320, y);

  y += 50 + t1.getHeight();

  textBox t2("Objective", "lazy.ttf", 32);
  t2.blitC(image, 320, y);

  y+= 15 + t2.getHeight();

  textBox obj1("Get the most points before dropping 3 balls","lazy.ttf",28);
  obj1.blitC(image, 320, y);

  y+= 25 +obj1.getHeight();

  textBox t3("Controls", "lazy.ttf", 32);
  t3.blitC(image, 320, y);

  y+= 25 + t3.getHeight();

  textBox t4("Left Paddle: z key", "lazy.ttf", 28);
  t4.blitC(image, 320, y);

  y+= 15 + t4.getHeight();

  textBox t5("Right Paddle: ? key", "lazy.ttf", 28);
  t5.blitC(image, 320, y);

  y+= 15 +t5.getHeight();

  textBox t6("To launch: space bar", "lazy.ttf", 28);
  t6.blitC(image, 320, y);

  y+= 15 + t6.getHeight();

  back = button("Back", "lazy.ttf", 32, 150, y);
  back.center(320);
  back.blit(image);
}

//displays instruction page and waits for click on back button
//returns 0 if successful, 1 if failed
int instructions::display(SDL_Surface *screen)
{
  if(image == NULL)
    {
      cout<<"instruction object has not been initialized"<<endl;
      return 1;
    }

  if(screen == NULL)
    {
      cout<<"Null pointer passed as parameter to instructions::display"<<endl;
      return 1;
    }

  SDL_BlitSurface(image, NULL, screen, NULL);
  SDL_Flip(screen);

  //waits until back is pressed
  while(wait()) SDL_Delay(100); //.1 sec pause after click to reset

  return 0;
}

//returns 0 when button is left clicked
int instructions::wait()
{
  SDL_PumpEvents();
  //waits for left click
  while(!(SDL_GetMouseState(NULL, NULL) == SDL_BUTTON_LEFT) )
    SDL_PumpEvents();

  //if mouse over back
  if(back.mouseOn()) return 0;

  return 1;
}

instructions::~instructions()
{
  SDL_FreeSurface(image);
}
