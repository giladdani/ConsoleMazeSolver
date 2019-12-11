#ifndef __POINT_H
#define __POINT_H

#include <iostream>
using namespace std;

class Point
{
public:
	Point() = default;
	Point(int row, int col);

	// Getters
	int getRow() const;
	int getCol() const;

private:
	int row, col;
};

#endif