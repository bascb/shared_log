CC=gcc
CFLAGS=-g -Wall -Werror -Wextra
FFLAGS=-fpic
SFLAGS=-shared

lib1000log.so: lib1000log.o
	$(CC) $(SFLAGS) -o lib1000log.so lib1000log.o

lib1000log.o: lib1000log.c 
	$(CC) -c $(CFLAGS) $(FFLAGS) lib1000log.c

deploy:
	cp lib1000log.so /usr/local/lib
	chmod 0755 /usr/lib/lib1000log.so
	cp lib1000log.h /usr/local/include
	ldconfig

clean:
	rm *.o *.so
