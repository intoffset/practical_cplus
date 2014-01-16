# Makefile

.PHONY: all clean

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =len
SRC      =len.cpp
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS) Makefile
	$(CC) -o $@ $(CFLAGS) $(SRC) $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)
