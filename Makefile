CXX = g++CXXFLAGS = -std=c++14 -g -Wall -O1OBJ = Params.o main.o FileID.o tools.oTARGETS = findit.PHONY: all cleanall: $(TARGETS)findit: $(OBJ)		$(CXX) -o $@ $(CXXFLAGS) $(OBJ)clean:		rm -f $(OBJ) $(TARGETS)#Dependencies:---------------------------------------------------------FileID.o: FileID.cpp FileID.hpp
Params.o: Params.cpp Params.hpp
main.o: main.cpp Params.hpp Tools.hpp
tools.o: tools.cpp tools.hpp
