/* Zach Lipp 3/27/13
used to create images of textBox and display them 
 */

#include <SDL/SDL.h>
#include "splashScreen.h"
#include <SDL/SDL_image.h>
#include <iostream>
#include <SDL/SDL_ttf.h>
#include <string>
#include "textBox.h"
using namespace std;

//default constructor, needed for composition .h
textBox::textBox()
{
  //Initialize SDL_ttf library
  if(TTF_Init() != 0 )
    {
      cout<<"TTF_Init Failed: "<< TTF_GetError()<<endl;
      return;
    }
}

//constructor passed pointer to screen and text to be displayed
textBox::textBox(string Sword, string f, int s)
{
  //Initialize SDL_ttf library
  if(TTF_Init() != 0 )
    {
      cout<<"TTF_Init Failed: "<< TTF_GetError()<<endl;
      return;
    }
  
  //sets everything
 setSize(s);
 if(setFont(f)) return;
 setWord(Sword);
 if(setImage()) return;
 if(setHandW()) return;  
}

//set font using file name and size
//return 0 if success
int textBox::setFont(string Sf)
{
  const char *f = Sf.c_str();;
  //load a font
  font = TTF_OpenFont(f, size);
  if(font==NULL)
    {
      cout<<"TTF OpenFont() Failed: " << TTF_GetError()<<endl;
      return 1;
    }
  return 0;
}

//set font give pointer to initialize font
void textBox::setFont(TTF_Font *f)
{
  font=f;
}

//sets height and width
//returns 0 when success
int textBox::setHandW()
{
  if( TTF_SizeText(font, word.c_str(), &width, &height) )
    {
  cout<<"TTF_SizeText() failed: "<<TTF_GetError()<<endl;
	return 1;
    }
  return 0;
}

//sets image
//returns 0 if successful
int textBox::setImage()
{
  //creates image and sets image as a pointer to the image
  SDL_Color text_color = {0, 0, 0};//color=white
  image = TTF_RenderText_Solid(font, word.c_str(), text_color);
  if(image == NULL)
    {
      cout<< "TTF_RenderText_Solid() Failed: " << TTF_GetError()<<endl;
      return 1;
    }
  return 0;
}

//sets size
void textBox::setSize(int s)
{
  size=s;
}


//sets word
void textBox::setWord(string str)
{
  word=str;
}

//if image is uninitialized returns 1
int textBox::uninit() const
{
  if(image==NULL)
    {
      cout<<"Constructor failed to create the image"<<endl;
      return 1;
    }
  return 0;
}

//blits text to screen with x,y at top right corner
//returns 0 if successful
int textBox::blit(SDL_Surface *screen, int x, int y) const
{
  if(uninit()) return 1;

  //Holds offsets
  SDL_Rect offset;

  //Get offsets
  offset.x = x;
  offset.y = y;

  //applies image to screen
  if(SDL_BlitSurface(image, 0, screen, &offset) != 0)
    {
      cout<<"SDL_BlitSurface() Failed in textBox.cpp: " <<SDL_GetError()<<endl;
      return 1;
    }

  return 0;
}

//returns width
int textBox::getWidth() const
{
  //if object uninitialized return 0;
  if(uninit()) return 0;
  return width;
}

//returns height
int textBox::getHeight() const
{
  if(uninit()) return 0;
  return height;
}

//returns word
string textBox::getWord() const
{
  return word;
}

//returns size
int textBox::getSize() const
{
  return size;
}

//returns font
TTF_Font *textBox::getFont() const
{
  return font;
}

void textBox::operator=(textBox t)
{
  setSize(t.getSize());
  setFont(t.getFont());
  setWord(t.getWord());
  setHandW();
  setImage();
}

//centers the textbox at x = c top of text box at y
//returns 0 if successful
int textBox::blitC(SDL_Surface *screen, int c, int y) const
{
  int x = c - width/2;
  return( blit(screen,x,y) );
}

textBox::~textBox()
{
  //double free problem
  //SDL_FreeSurface(image);   
  TTF_Quit();
}

