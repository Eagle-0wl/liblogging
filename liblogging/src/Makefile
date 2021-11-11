BIN:=app_logging
CC:=gcc
CPPFLAGS:=-I$(CURDIR) -w -fpic -L./lib -llogging
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	$(RM) $(BIN) $(OBJS)
