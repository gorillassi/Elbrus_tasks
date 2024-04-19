CXX=g++
CXXFLAGS=-Wall -std=c++11

SRCS = algorithm.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = max_sum_algorithm

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

algorithm.o: algorithm.cpp algorithm.hpp
	$(CXX) $(CXXFLAGS) -c algorithm.cpp

main.o: main.cpp algorithm.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

.PHONY: clean

clean:
	rm -f *.o $(EXEC)
