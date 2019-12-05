#include "Maze.h"

// c'tor
Maze::Maze(char** mat, int rows, int cols) : mat(mat), rows(rows), cols(cols) {}

// move c'tor
Maze::Maze(Maze&& other)
{
	this->mat = other.mat;
	this->rows = other.rows;
	this->cols = other.cols;

	other.mat = nullptr;
}

// d'tor
Maze::~Maze()
{
	if(mat != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete mat[i];
		}
	}
	delete []mat;
}

//---------------------------------------SETTERS---------------------------------------
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
	cout << "Here is the maze:" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << mat[i] << endl;
	}
}