/* Zach Lipp   4/8/13
Button class implementation
Displays a textBox image that can respond when left clicked on.
*/

#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include "textBox.h"
#include "button.h"
using namespace std;

button::button():textBox()//needed for composition
{}

button::button(string word, string f, int size, int xPos, int yPos):textBox(word,f,size)
{
  x = xPos;
  y = yPos;
}

//blits button to screen
//returns 0 if success
int button::blit(SDL_Surface *screen)
{
  return( textBox::blit(screen,x,y) );
}

//centers button on x=c
void button::center(int c)
{
  x = c - getWidth()/2;
}

//returns 1 if mouse is on the button
int button::mouseOn()
{
  //indicate position 
  int xMouse, yMouse;
  SDL_GetMouseState(&xMouse,&yMouse);

  if(xMouse < x ) return 0;//too far left
  if(xMouse > x+getWidth()) return 0;//too far right
  if(yMouse < y ) return 0; //too high
  if(yMouse > y+getHeight() ) return 0; // too low
  
  //just right
  return 1;
}

int button::getX()//returns x
{
  return x;
}

//returns y
int button::getY()
{
  return y;
}

//sets x
void button::setX(int posX)
{
  x=posX;
}

//sets y
void button::setY(int posY)
{
  y=posY;
}

//sets this button equal to b
void button::operator=(button b)
{
  setY(b.getY());
  setX(b.getX());
  textBox::operator=(b);
}
