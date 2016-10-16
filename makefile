GCC = gcc -g

all: stest ptest

stest: songz.o playlist.o stest.o
	$(GCC) songz.o playlist.o stest.o -o stest

ptest: songz.o playlist.o ptest.o
	$(GCC) songz.o playlist.o ptest.o -o ptest

songz.o: songz.c songz.h
	$(GCC) -c songz.c

stest.o: stest.c songz.h
	$(GCC) -c stest.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

ptest.o: ptest.c playlist.h
	$(GCC) -c ptest.c

clean:
	rm *.o
	rm *~
	rm *#
