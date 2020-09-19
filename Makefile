CXX = g++

CXXFLAGS = -std=c++14 -g -Wall -O1

OBJ = Params.o main.o

TARGETS = findit

.PHONY: all clean

all: $(TARGETS)

findit: $(OBJ)
		$(CXX) -o $@ $(CXXFLAGS) $(OBJ)

clean:
		rm -f $(OBJ) $(TARGETS)

#Dependencies:---------------------------------------------------------
Params.o: Params.cpp Params.hpp
main.o: main.cpp Params.hpp
