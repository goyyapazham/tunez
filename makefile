GCC = gcc -g

all: songz.o ttest.o
	$(GCC) songz.o ttest.o -o test

songz.o: songz.c songz.h
	$(GCC) -c songz.c

ttest.o: ttest.c songz.h
	$(GCC) -c ttest.c

clean:
	rm *.o
	rm *.c~
	rm *#
