# Lecture 5 makefile.

CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

all: test

test: functions_to_implement.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp functions_to_implement.o -o test 

functions_to_implement.o: functions_to_implement.cpp
	$(CXX) $(CXXFLAGS) -c functions_to_implement.cpp

clean:
	rm functions_to_implement.o test