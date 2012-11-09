CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
PROGRAMS=dna

all: $(PROGRAMS)
