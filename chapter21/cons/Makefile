# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =class
OBJS     =class.o
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

class.o: class.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
