CC=gcc
CFLAGS=-g -Wall -Werror -Wextra
FFLAGS=-fpic
SFLAGS=-shared

lib1000log.so: lib1000log.o
	$(CC) $(SFLAGS) -o lib1000log.so lib1000log.o

lib1000log.o: lib1000log.c 
	$(CC) -c $(CFLAGS) $(FFLAGS) lib1000log.c

.PHONY: clean install uninstall all

install: lib1000log.so
	cp lib1000log.so /usr/lib
	chmod 0755 /usr/lib/lib1000log.so
	cp lib1000log.h /usr/include
	ldconfig

uninstall:
ifneq (,$(wildcard /usr/lib/lib1000log.so))
	rm /usr/lib/lib1000log.so
endif
ifneq (,$(wildcard /usr/include/lib1000log.h))
	rm /usr/include/lib1000log.h
	ldconfig
endif

all: uninstall install clean

clean:
	rm *.o *.so
