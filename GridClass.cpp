#include "GridClass.h"

GridClass::GridClass()
{
  for (int i = 0; i < MAXCELLS; ++i)
  {
    grid[i] = 0;
  }
}

void GridClass::getRow(const int rowNum, int row[]) const
{
  int startIndex = (rowNum - 1) * 9;
  for (int i = 0; i < 9; ++i)
  {
    row[i] = grid[startIndex + i];
  }
}

void GridClass::getCol(const int colNum, int col[]) const
{
  for (int i = 0; i < 9; ++i)
  {
    col[i] = grid[(colNum - 1) + (i * 9)];
  }
}

void GridClass::getBox(const int boxNum, int box[]) const
{
  int x1 = (boxNum - 1) / 3;
  int x2 = (boxNum - 1) % 3;
  int startingIndex = 27 * x1 + 3 * x2;
  
  for (int i = 0; i < 9; ++i)
  {
    box[i] = grid[startingIndex + 9 * (i/3) + (i % 3)];
  }
}

int GridClass::getBoxNum(const int row, const int col) const
{
  int rowNum = (row-1) / 3;
  int colNum = (col-1) / 3;
  return rowNum * 3 + colNum + 1;
}

void GridClass::loadGrid(const string fname)
{
  ifstream inFile;
  string line;
  string val;
  
  inFile.open(fname.c_str());
  
  for (int i = 0; i < MAXCELLS; ++i)
  {
    if (i % 9 == 0)
    {
      getline(inFile, line);
    }
    
    val = line[i % 9];
    grid[i] = atoi(val.c_str());
  }
  
  inFile.close();
}

void GridClass::writeCell(const int row, const int col, const int val)
{
  grid[(row - 1) * 9 + (col - 1)] = val;
}

void GridClass::printGrid()
{
  int val;
  bool newline = true;
  
  cout << "\t-------------------------" << endl;
  
  for (int i = 0; i < 9; ++i)
  {
    for (int j = 0; j < 9; ++j)
    {
      if (j % 3 == 0)
      {
        if (newline)
        {
          cout << "\t";
        }
        cout << "| ";
        newline = false;
      }
      val = grid[i*9 + j];
      if (val != 0)
      {
        cout << val << " ";
      }
      else
      {
        cout << "  ";
      }
    }
    cout << "|" << endl;
    if (i % 3 == 2)
    {
      cout << "\t-------------------------" << endl;
    }
    newline = true;
  }
  
}

int GridClass::readCell(const int row, const int col)
{
  return grid[(row - 1) * 9 + (col - 1)];
}
