#include "GridClass.h"
#include <sys/time.h>

bool solveSudoku(GridClass& grid);

int main()
{
  GridClass board;
  string fname;
  bool solved;
  
  cout << "Input file name of puzzle: ";
  cin  >> fname;
  
  board.loadGrid(fname);
  cout << endl << "Puzzle loaded!" << endl;
  board.printGrid();
  
  cout << endl << "Solving puzzle... ";
  
  timeval startTime, endTime;
  gettimeofday(&startTime, NULL);
  solved = solveSudoku(board);
  gettimeofday(&endTime, NULL);
  
  if (solved)
  {
    cout << "[Success!]" << endl;
  }
  else
  {
    cout << "[Failed!]" << endl;
    cout << "ERROR: Puzzle is not solvable" << endl;
  }
  
  double interval = endTime.tv_sec - startTime.tv_sec + 
                    (endTime.tv_usec - startTime.tv_usec) * 1e-6;
  cout << "Total time to solve: " <<  interval << " seconds" << endl;
  
  cout << endl << "Result: " << endl;
  board.printGrid();
  
  return 0;
}
