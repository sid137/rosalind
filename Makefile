CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
SOURCES=$(wildcard *.c)
EXEC=$(patsubst %.c,%,$(SOURCES))

all: $(EXEC)


clean:
	rm $(EXEC)
