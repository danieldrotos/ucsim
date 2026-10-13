OBJECTS         = pobj.o globals.o utils.o \
		  serr.o app.o option.o chars.o \
		  fio.o

ifeq ($(WINSOCK_AVAIL), 1)
OBJECTS		+= fwio.o
else
OBJECTS		+= fuio.o
endif
