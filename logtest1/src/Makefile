
BIN:=logtest1
CC:=gcc
CPPFLAGS:=-I$(CURDIR) -w
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^ -llogging

clean:
	$(RM) $(BIN) $(OBJS)
