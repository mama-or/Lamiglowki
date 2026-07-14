CXX = g++
CFLAGS = -Wall -Wextra -Werror -g -Isrc
CXXFLAGS = $(CFLAGS) -std=c++26
LDFLAGS = -g

SRC = $(shell find src -name *.cpp)
OBJ = $(SRC:src%.cpp=build/%.o)

all: lamiglowki

build/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) -c -o $(abspath $@) $^ $(CXXFLAGS)

lamiglowki: $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf build lamiglowki.exe

.PHONY: clean

