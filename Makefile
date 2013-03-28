all: main

main: main.o ball.o
	g++ -o main -lSDL -lSDL_image -lpthread main.o

main.o: main.cpp
	g++ `sdl-config --cflags` -c main.cpp

ball.o: ball.cpp
	g++ `sdl-config --cflags` -c main.cpp
