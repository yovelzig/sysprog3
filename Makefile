CC=gcc
FLAGS = -Wall -g
ALL_M= isort.o isort txtfind.o txtfind
 
all:$(ALL_M)

isort: isort.o
	$(CC) $(FLAGS) isort.o -o sort

isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c
txtfind: txtfind.o
	$(CC) $(FLAGS) txtfind.o -o txtfind 		

.PHONY: clean

clean:
	rm -f *.o *.a *.so $(ALL_M)

 