/* Zach Lipp 3/27/13
text object used to create images of text and display them

 */

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
#include <SDL/SDL_ttf.h>
using namespace std;

class textBox
{
 public:
  textBox();//default constructor 
  textBox(string Sword, string f, int size);//constructor passed content, font, and size of text to be displayed.
  int blit(SDL_Surface *screen, int x, int y) const;//blits text to screen with x,y at top right corner, returns 0 if successful
  int blitC(SDL_Surface *screen, int c, int y) const; //blits text with c, y at top center of the textbox

  //these function are used to make composition and the = operator possible
  int getSize() const; //returns size
  TTF_Font *getFont() const;
  string getWord() const;//returns word

  //these functions are used by button
  int getHeight() const;//returns height
  int getWidth() const;//returns width
  
  void operator=(textBox); //overloading equals operator
  ~textBox();  //deconstructor


 private:
  SDL_Surface *image;//pointer to text image
  int width;//width of image
  int height; //height of image
  int uninit() const;//checks if object is initialized, returns 1 if not
  TTF_Font *font;//points to the font
  string word;//word displayed, stored as string
  int size;//font size  
  
  //these function are used to make composition and the = operator possible
  int setHandW();//sets HandW based on word, size, and font
  int setImage();//sets image based on word, font, and size
  void setWord(string); //sets word to input
  int setFont(string); //sets font given name of .ttf file
  void setFont(TTF_Font *); //sets font given another font
  void setSize(int);//sets size to input
};

#endif
