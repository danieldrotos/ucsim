CC		= g++
CFLAGS	= -Wall -O2 -g -ansi -pedantic
EXES	= basic append explode
OBJS	= basic.o append.o explode.o

all: src basic append explode

src:
	cd ../src; $(MAKE)

basic: basic.o
	$(CC) $(CFLAGS) basic.o -L../src -lgstring -o basic

basic.o: basic.cxx
	$(CC) $(CFLAGS) -I../src -c basic.cxx

append: append.o
	$(CC) $(CFLAGS) append.o -L../src -lgstring -o append

append.o: append.cxx
	$(CC) $(CFLAGS) -I../src -c append.cxx

explode: explode.o
	$(CC) $(CFLAGS) explode.o -L../src -lgstring -o explode

explode.o: explode.cxx
	$(CC) $(CFLAGS) -I../src -c explode.cxx

clean:
	rm -f $(EXES) $(OBJS) core 
