TARGET   := main
CC       := gcc
CPP		 := g++
CFLAGS   := -std=c99 -O2
CPPFLAGS := -std=c++11 -O2
WARN     := -Wall -Wextra -Wno-format -pedantic
LIBS     :=
INCPATH  :=
LDPATH   :=
OBJECTS  := main.o Quadtree.o

all:	main

main: ${OBJECTS}
	${CPP} ${OBJECTS} -o main ${LIBS}

main.o: main.cpp
	${CPP} ${CPPFLAGS} ${WARN} -c main.cpp

Quadtree.o: Quadtree.cpp Quadtree.hpp
	${CPP} ${CPPFLAGS} ${WARN} -c Quadtree.cpp


clean:
	-rm *.o main
