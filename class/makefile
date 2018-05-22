# $@ target
# $^ dependencies
# 1 characted long variable names don't need ()
# CXX built-in variable, which defaults to c++

CC := g++ -Wall # Compiler 

SRCEXT = cpp 
SRCDIR = src
BUILDDIR = build

OBJECTS = main.o player.o

TARGET = output

$(TARGET): $(OBJECTS)
	g++ -o $@ $(OBJECTS)
main.o: player.hpp
player.o: player.hpp

.PHONY : clean
clean:
	rm *.o $(TARGET)
