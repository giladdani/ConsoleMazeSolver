#include "Point.h"

// c'tor
Point::Point(int row, int col) : row(row), col(col) {}

// Getters
int Point::getRow() const
{
	return row;
}
int Point::getCol() const
{
	return col;
}
