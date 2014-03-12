sudoku: main.o GridClass.o solver.o
	g++ -Wall -Werror main.o GridClass.o solver.o -o sudoku

main.o: main.cpp
	g++ -c main.cpp -o main.o
	
GridClass.o: GridClass.cpp GridClass.h
	g++ -c GridClass.cpp -o GridClass.o
	
solver.o: solver.cpp
	g++ -c solver.cpp -o solver.o
	
clean:
	rm -rf main.o GridClass.o sudoku
