CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG -L. -lpermutation -lprinting -Bstatic $(OPTFLAGS)
SOURCES=$(wildcard *.c)
EXEC=$(patsubst %.c,%,$(SOURCES))
LIBRARIES=print_library permutation
LIBRARIES_STATIC=$(patsubst %, %.o, $(LIBRARIES))

all: $(LIBRARIES) $(EXEC) libs 


clean:
	rm *.a *.o
	rm $(EXEC)

libs: $(LIBRARIES_STATIC)

print_library: libs
	ar rcs libprinting.a print_library.o

permutation: libs
	ar rcs libpermutation.a permutation.o
