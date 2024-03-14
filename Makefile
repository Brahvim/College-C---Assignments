CC = g++
CXXFLAGS = -std=c++23 -Wall

SRC = ./src/FileOutputStream.cpp
TARGET = FileOutputStream.out

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGET)
