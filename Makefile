Makefile: main.o
	g++ -o BET.x main.o

main.o: main.cpp bet.h bet.hpp
	g++ -c main.cpp

clean: 
	rm -f BET.x main.o

run: BET.x
	./BET.x
