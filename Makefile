CXX = g++

CXXFLAGS = -std=c++14 -g -Wall -O1

OBJ = Params.o main.o FileID.o tools.o Sniff.o

TARGETS = findit

.PHONY: all clean

all: $(TARGETS)

findit: $(OBJ)
		$(CXX) -o $@ $(CXXFLAGS) $(OBJ)

clean:
		rm -f $(OBJ) $(TARGETS)

#Dependencies:---------------------------------------------------------
FileID.o: FileID.cpp FileID.hpp Params.hpp tools.hpp
Params.o: Params.cpp Params.hpp tools.hpp
Sniff.o: Sniff.cpp Sniff.hpp FileID.hpp Params.hpp tools.hpp
main.o: main.cpp Sniff.hpp FileID.hpp Params.hpp tools.hpp
tools.o: tools.cpp tools.hpp
