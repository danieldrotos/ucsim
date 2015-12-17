CC		= g++
CFLAGS	= -Wall -O2 -g -ansi -pedantic
OBJS	= gstring.o
PREFIX	= /nfs/home/cia/drewpc/local

all: lib

lib: gstring.o
	ar cru libgstring.a gstring.o
	ranlib libgstring.a

gstring.o: gstring.cxx gstring.h
	$(CC) $(CFLAGS) -c gstring.cxx

install:
	install -c -m 0644 gstring.h $(PREFIX)/include
	install -c -m 0644 libgstring.a $(PREFIX)/lib

clean:
	rm -f $(OBJS) core libgstring.a
