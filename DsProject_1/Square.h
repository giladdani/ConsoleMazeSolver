#ifndef __SQUARE_H
#define __SQUARE_H

#include <iostream>
using namespace std;

class Square
{
public:
	Square(int row, int col);
	int getRow() const;
	int getCol() const;

private:
	int row, col;
};

#endif