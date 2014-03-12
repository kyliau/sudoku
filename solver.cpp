#include "constants.h"
#include "GridClass.h"

bool findUnfilledCell(GridClass& grid, int& row, int& col);
bool noConflict(const GridClass& grid, 
                const int rowID, const int colID, const int num);

bool solveSudoku(GridClass& grid)
{
  int row, col;
  
  if (!findUnfilledCell(grid, row, col))
  {
    return true;
  }
  
  for (int num = 1; num <= 9; ++num)
  {
    if (noConflict(grid, row, col, num))
    {
      grid.writeCell(row, col, num);
      if (solveSudoku(grid))
      {
        return true;
      }
      grid.writeCell(row, col, UNFILLED);
    }
  }
  
  return false;
}

bool findUnfilledCell(GridClass& grid, int& row, int& col)
{
  for (row = 1; row <= 9; ++row)
  {
    for (col = 1; col <= 9; ++col)
    {
      if (grid.readCell(row, col) == UNFILLED)
      {
        return true;
      }
    }
  }
  return false;
}

bool noConflict(const GridClass& grid, 
                const int rowID, const int colID, const int num)
{
  int row[9], col[9], box[9];
  bool usedInRow, usedInCol, usedInBox;
  
  grid.getRow(rowID, row);
  grid.getCol(colID, col);
  grid.getBox(grid.getBoxNum(rowID, colID), box);
  
  usedInRow = false;
  usedInCol = false;
  usedInBox = false;
  for (int i = 0; i < 9; ++i)
  {
    if (row[i] == num)
      usedInRow = true;
    if (col[i] == num)
      usedInCol = true;
    if (box[i] == num)
      usedInBox = true;
  }
  
  return (!usedInRow && !usedInCol && !usedInBox);
}

