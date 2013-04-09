main: main.o textBox.o button.o splashScreen.o
  g++ main.o textBox.o button.o splashScreen.o -o main -lSDL -lSDL_image -lpthread -lSDL_ttf
main.o: main.cpp splashScreen.h 
	g++ -c main.cpp -lSDL `sdl-config --cflags` `sdl-config --libs`
splashScreen.o: splashScreen.cpp splashScreen.h button.h textBox.h
	g++ -c splashScreen.cpp -lSDL `sdl-config --cflags` `sdl-config --libs`
button.o: button.cpp button.h textBox.h
	g++ -c button.cpp -lSDL
textBox.o: textBox.cpp textBox.h
	g++ -c textBox.cpp -lSDL -lSDL_ttf
clean:
	rm -f *.o main *~
