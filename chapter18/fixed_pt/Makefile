# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =fixed_pt
OBJS     =fixed_test.o fixed_pt.o
HEADERS  =fixed_pt.h
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

fixed_test.o: fixed_test.cpp $(HEADERS) Makefile
fixed_pt.o: fixed_pt.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
