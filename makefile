#modify this makefile so that it will work for this new assignment
CC=g++
DEPS = starter.h

all: main.o
	$(CC) -std=c++11 main.o

# bowling: starter.o $(DEPS)
# 	$(CC) -c -std=c++11 starter.cpp

main: main.o $(DEPS)
	$(CC) -c -std=c++11 main.cpp

clean: 
	rm *.o *.out
