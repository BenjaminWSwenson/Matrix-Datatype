  CC = g++
  CFLAGS = -Iheaders
  LDFLAGS = -std=c++11 -pthread
  TARGET = test
  
  all: Matrix.o
	$(CC) $(CFLAGS) scr/test.cpp -o test Matrix.o $(LDFLAGS)
  Matrix.o: scr/Matrix.cpp headers/Matrix.h
	$(CC) $(CFLAGS) scr/Matrix.cpp -o $@ $(LDFLAGS)
  clean:
	$(RM) test *.o *~
