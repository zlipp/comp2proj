all: main

main: main.o ball.o board.o circlebumper.o item.o
	g++ -o main -lSDL -lSDL_image -lpthread main.o ball.o board.o circlebumper.o item.o

main.o: main.cpp
	g++ `sdl-config --cflags` -c main.cpp

ball.o: ball.cpp
	g++ `sdl-config --cflags` -c ball.cpp

board.o: board.cpp
	g++ `sdl-config --cflags` -c board.cpp

circlebumper.o: circlebumper.cpp
	g++ `sdl-config --cflags` -c circlebumper.cpp

item.o: item.cpp
	g++ `sdl-config --cflags` -c item.cpp
