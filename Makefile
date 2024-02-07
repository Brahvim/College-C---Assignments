CC = g++
CXXFLAGS = -std=c++23 -Wall

SRC = ./src/Main.cpp
TARGET = Main.out

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f $(TARGET)
