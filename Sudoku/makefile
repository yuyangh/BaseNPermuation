all: sudoku NQueen

NQueen: NQueen.cpp
	g++ -g -Wall NQueen.cpp -o NQueen

sudoku: sudoku.o main.cpp
	g++ -g -Wall main.cpp sudoku.o -o sudoku

sudoku.o: sudoku.cpp sudoku.h
	g++ -g -Wall -c sudoku.cpp -o sudoku.o

clean:
	-@rm NQueen 
	-@rm sudoku 
	-@rm sudoku.o
