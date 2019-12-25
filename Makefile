CC=gcc
FLAGS= -Wall -g

# creates all.
all: txtfind isort

# Creates isort.o
isort: isort.o 
	$(CC) $(FLAGS) -o isort isort.o
	
# Creates isort.c
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -c isort.c 
	
# Creates txtfind.o
txtfind: txtfind.o 
	$(CC) $(FLAGS) -o txtfind txtfind.o
	
# Creates txtfind.c
txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c 

.PHONY: clean all

#Cleans files.
clean:
	rm -f *.o *.a *.so txtfind isort 