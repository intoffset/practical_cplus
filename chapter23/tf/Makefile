# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =main
OBJS     =main.o count.o
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

main.o: main.cpp $(HEADERS) Makefile
count.o: count.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
