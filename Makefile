CC		?= gcc
DEBUG	?= -g -O0 -march=native

override CFLAGS		+= $(DEBUG) -Wall -Wextra -std=c99 -pedantic
override LDFLAGS	+=
override LDLIBS		+=

SRC		:= $(wildcard *.c)
OBJ		:= $(SRC:.c=.o)
SYM		:= $(SRC:.c=.o.dSYM)
BIN		:= sysinfo

PREFIX	?= /usr/local
BINDIR	:= $(PREFIX)/bin

.PHONY: clean

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(BIN)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


install: $(BIN)
	install -d $(BINDIR)
	install $(BIN) $(BINDIR)

clean:
	rm -rf $(OBJ) $(BIN)

