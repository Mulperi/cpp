output: main.o player.o
	g++ main.o player.o -o output

main.o: main.cpp
	g++ -c main.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm *.o output
