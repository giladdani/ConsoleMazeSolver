#include "Square.h"

Square::Square(int row, int col) : row(row), col(col) {}

int Square::getRow() const
{
	return this->row;
}

int Square::getCol() const
{
	return this->col;
}
