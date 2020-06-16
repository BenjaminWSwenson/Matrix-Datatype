  CC = g++
  LDFLAGS = -std=c++11 -pthread
  TARGET = MatrixCalculator
  
  all: $(TARGET) 
	$(CC) $(TARGET).cpp -o $(TARGET) $(LDFLAGS)
  clean:
	$(RM) $(TARGET)
