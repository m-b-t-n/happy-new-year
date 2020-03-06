#
# Copyright 2020 m-b-t-n <mbtn_0xff@outlook.com>
#

TARGET  := hny
CFLAGS  := -Wall -Werror
CC      := gcc
SOURCES := hny.c
OBJS    := $(SOURCES:.c=.o)

.PHONY: all clean exec

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(OBJS) -o $(TARGET)

$(OBJS): $(SOURCES)
	@$(CC) $(CFLAGS) -c $(SOURCES)

exec: $(TARGET)
	@./$(TARGET)

clean:
	@rm -f $(OBJS) $(TARGET)

