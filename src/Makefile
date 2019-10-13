CXX=g++
RM=rm
CXXFLAGS= -std=c++11
SRC=  type.cpp deck.cpp
OBJS=$(SRC:%.cpp=%.o)
EXE=main
.PHONY: clean


EXE:$(OBJS)
	$(CXX) -o $(EXE) $(CXXFLAGS)  main.cpp $(OBJS)

OBJS:$(SRC)

    

clean:
	$(RM) *.o *.gch

