# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =main
OBJS     =main.o square2.o
HEADERS  =integer.h square.h
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

main.o: main.cpp $(HEADERS) Makefile
square2.o: square2.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
