GCC = gcc -g

all: songz.o playlist.o ptest.o
	$(GCC) songz.o playlist.o ptest.o -o test

songz.o: songz.c songz.h
	$(GCC) -c songz.c

ttest.o: ttest.c songz.h
	$(GCC) -c ttest.c

playlist.o: playlist.c playlist.h
	$(GCC) -c playlist.c

ptest.o: ptest.c playlist.h
	$(GCC) -c ptest.c

clean:
	rm *.o
	rm *~
	rm *#
