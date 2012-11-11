CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -L. -lprinting -Bstatic $(OPTFLAGS)
SOURCES=$(wildcard *.c)
EXEC=$(patsubst %.c,%,$(SOURCES))
LIBRARIES=print_library
LIBRARIES_STATIC=$(patsubst %, %.o, $(LIBRARIES))

all: print_library $(EXEC) libs 


clean:
	rm *.a *.o
	rm $(EXEC)

libs: $(LIBRARIES_STATIC)

print_library: libs
	ar rcs libprinting.a print_library.o
