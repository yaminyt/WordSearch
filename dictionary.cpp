#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

class grid
{
public:
    void readGrid(const string& filename);
    int rows() const;
    int cols() const;
    char getLetter(int i, int j) const;

private:
    matrix<char> letters;
};

#endif
