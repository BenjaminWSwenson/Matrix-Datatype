  CC = g++
  CFLAGS = -Iinclude
  LDFLAGS = -std=c++11 -pthread
  TARGET = test
  
  all: src/test.cpp src/Matrix.cpp
	$(CC) $(CFLAGS) $^ -o $(TARGET) $(LDFLAGS)
  clean:
	$(RM) test
