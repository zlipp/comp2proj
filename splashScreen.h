/* Zach Lipp 3/27/13
Splash Screen 
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>
using namespace std;

class splashScreen
{
 public:
  splashScreen();//default constructor, loads splashScreen.bmp then is pointed to by image
  int display(SDL_Surface *); //displays the splash screen on the screen passed in
  ~splashScreen();

 private:
  SDL_Surface *image; 
};
