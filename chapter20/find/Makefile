# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =find
OBJS     =find.o
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

find.o: find.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
