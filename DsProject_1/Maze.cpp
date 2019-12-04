#include "Maze.h"

Maze::Maze(char** mat, int rows, int cols) : mat(mat), rows(rows), cols(cols) {}

bool Maze::setMat(char** mat)
{
	this->mat = mat;
	return true;
}
bool Maze::setRows(int rows)
{
	this->rows = rows;
	return true;
}
bool Maze::setCols(int cols)
{
	this->cols = cols;
	return true;
}

// print
void Maze::print()
{
	for (int i = 0; i < rows; i++)
	{
		cout << mat[i] << endl;
	}
}