#ifndef _GRIDCLASS_H_
#define _GRIDCLASS_H_

#include "constants.h"
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

class GridClass
{
  private:
    int grid[MAXCELLS];
    
  public:
    GridClass();
    void getRow(const int, int []) const;
    void getCol(const int, int []) const;
    void getBox(const int, int []) const;
    void loadGrid(const string);
    void writeCell(const int, const int, const int);
    void printGrid();
    int readCell(const int, const int);
    int getBoxNum(const int, const int) const;
};

#endif
