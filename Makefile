CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -L. -lprinting -Bstatic $(OPTFLAGS)
SOURCES=$(wildcard *.c)
EXEC=$(patsubst %.c,%,$(SOURCES))
LIBRARIES=print_library
LIBRARIES_STATIC=$(patsubst %, %.o, $(LIBRARIES))

all: $(EXEC) libs


clean:
	rm $(EXEC)

libs: $(LIBRARIES_STATIC)

print_library:
	ar rcs libprinting.a print_library.o
