# Makefile

.PHONY: all clean

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =bound_c2
SRC      =bound_c2.cpp
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS) Makefile
	$(CC) -o $@ $(CFLAGS) $(SRC) $(INCLUDES) $(LDFLAGS) $(LIBS)

clean:
	rm -f $(TARGET)
