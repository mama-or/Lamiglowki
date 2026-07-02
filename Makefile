CXX = g++
CFLAGS = -Wall -Wextra -Werror
CXXFLAGS = $(CFLAGS) -std=c++23
LDFLAGS = 

SRC = $(shell find . -name *.cpp)
OBJ = $(SRC:%.cpp=build/%.o)

all: lamiglowki

build/%.o: %.cpp
	mkdir -p $(@D)
	$(CXX) -c -o $@ $^ $(CXXFLAGS)

lamiglowki: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf build lamiglowki

.PHONY: clean

