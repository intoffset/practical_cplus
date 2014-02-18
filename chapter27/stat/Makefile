# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =stat
OBJS     =stat.o token.o ch_type.o
HEADERS  =token.h ch_type.h
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

stat.o: stat.cpp $(HEADERS) Makefile
token.o: token.cpp $(HEADERS) Makefile
ch_type.o: ch_type.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
