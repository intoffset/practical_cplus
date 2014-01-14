# Makefile

.PHONY: all clean

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =hello
SRC      =hello.cpp
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)
