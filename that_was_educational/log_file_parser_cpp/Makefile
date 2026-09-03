#File: Makefile

default: main.exe

Line.o: Line.cpp
	g++ -c Line.cpp
main.o: main.cpp Line.o
	g++ -c main.cpp
main.exe: main.o Line.o
	g++ main.o Line.o -o main.exe
clean:
	rm *.o *.exe 

