# Makefile

.PHONY: all clean

.SUFFIXES:
.SUFFIXES: .o .cpp

CC       =g++
CFLAGS   =-Wall -ansi -pedantic
TARGET   =matrix
OBJS     =matrix1.o matrix2.o matrix3.o matrix4.o \
		  matrix5.o matrix6.o matrix7.o matrix8.o
HEADERS  =
INCLUDES =
LDFLAGS  =
LIBS     =

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(CFLAGS) $^ $(INCLUDES) $(LDFLAGS) $(LIBS)

.cpp.o:
	$(CC) -o $@ $(CFLAGS) -c $< $(INCLUDES)

matrix1.o: matrix1.cpp $(HEADERS) Makefile
matrix2.o: matrix2.cpp $(HEADERS) Makefile
matrix3.o: matrix3.cpp $(HEADERS) Makefile
matrix4.o: matrix4.cpp $(HEADERS) Makefile
matrix5.o: matrix5.cpp $(HEADERS) Makefile
matrix6.o: matrix6.cpp $(HEADERS) Makefile
matrix7.o: matrix7.cpp $(HEADERS) Makefile
matrix8.o: matrix8.cpp $(HEADERS) Makefile

clean:
	rm -f $(TARGET) $(OBJS)
