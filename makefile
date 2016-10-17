GCC = gcc -g

all: stest ptest

stest: songlist.o playlist.o stest.o
	$(GCC) songlist.o playlist.o stest.o -o stest

ptest: songlist.o playlist.o ptest.o
	$(GCC) songlist.o playlist.o ptest.o -o ptest

songlist.o: songlist.c songlist.h
	$(GCC) -c songlist.c

stest.o: stest.c songlist.h
	$(GCC) -c stest.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

ptest.o: ptest.c playlist.h
	$(GCC) -c ptest.c

clean:
	rm *.o
	rm *~
	rm *#
