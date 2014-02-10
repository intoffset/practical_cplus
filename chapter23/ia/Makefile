# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =hist
OBJS     =hist.o ia.o
HEADERS  =ia.h
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

hist.o: hist.cpp $(HEADERS) Makefile
ia.o: ia.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
