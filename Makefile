#############################################################################
# File name:  Makefile
# Author:     chadd williams
# Date:       Sept 1, 2021
# Class:      CS360
# Assignment: 
# Purpose:    
#############################################################################

all: bin bin/main bin/Examples_2

bin:
	mkdir -p bin

bin/main: bin/main.o
	gcc -o bin/main -g -Wall bin/main.o

bin/main.o: bin src/main.c
	gcc -c -o bin/main.o -g -Wall src/main.c

bin/Examples_2: bin/Examples_2.o
	gcc -o bin/Examples_2 -g -Wall bin/Examples_2.o

bin/Examples_2.o: bin src/Examples_2.c
	gcc -c -o bin/Examples_2.o -g -Wall src/Examples_2.c

clean:
	rm -f bin/main bin/*.o bin/Examples_2
