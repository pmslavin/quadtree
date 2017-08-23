TARGET   := main
CC       := gcc
CPP		 := g++
CFLAGS   := -g -std=c99 -O2
CPPFLAGS := -g -std=c++11 -O2
WARN     := -Wall -Wextra -Wno-format -pedantic
LIBS     := -lm -lSDL2
INCPATH  :=
LDPATH   :=
OBJECTS  := main.o Quadtree.o Frame.o

all:	main

main: ${OBJECTS}
	${CPP} ${OBJECTS} -o main ${LIBS}

main.o: main.cpp
	${CPP} ${CPPFLAGS} ${WARN} -c main.cpp

Quadtree.o: Quadtree.cpp Quadtree.hpp
	${CPP} ${CPPFLAGS} ${WARN} -c Quadtree.cpp

Frame.o: Frame.cpp Frame.hpp
	${CPP} ${CPPFLAGS} ${WARN} -c Frame.cpp


clean:
	-rm *.o main
