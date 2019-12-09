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
//---------------------------------------GETTERS---------------------------------------
int Maze::getRows()	const
{
	return this->rows;
}
int Maze::getCols() const
{
	return this->cols;
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
void Maze::print() const
{
	cout << "Here is the maze:" << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << mat[i] << endl;
	}
}

// marks the given coordinate with '$' as "visited"
void Maze::markSquare(int row, int col)
{
	this->mat[row][col] = '$';
}

// create starting maze
void Maze::createStartingMaze(int rows, int cols)
{
	this->mat = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		this->mat[i] = new char[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			if (i % 2 == 0)
				this->mat[i][j] = '*';
			else
			{
				if (j % 2 == 0)
					this->mat[i][j] = '*';
				else
					this->mat[i][j] = ' ';
			}
		}
		this->mat[i][cols] = '\0';
	}
}


Square** Maze::getSquareNeighbors(int row, int col, bool &flag, int& size)
{
	size = 0;
	Square** neighbors = new Square*[4];

	if (col + 2 < this->getCols() && (this->mat[row][col + 2] == ' '))
	{
		neighbors[size] = new Square(row, col + 2);
		flag = true;
		size++;
	}

	if (row + 2 < this->getRows() && (this->mat[row + 2][col] == ' '))
	{
		neighbors[size] = new Square(row + 2, col);
		flag = true;
		size++;
	}

	if ((col - 2 > 0) && (this->mat[row][col - 2] == ' '))
	{
		neighbors[size] = new Square(row, col - 2);
		flag = true;
		size++;
	}
		
	if ((row - 2 > 0) && (this->mat[row - 2][col] == ' '))
	{
		neighbors[size] = new Square(row - 2, col);
		flag = true;
		size++;
	}
	return neighbors;
}
void Maze::BreakWall(const Square *curr, Square *neighbor)
{
	int colDiff = curr->getCol() - neighbor->getCol();
	int rowDiff = curr->getRow() - neighbor->getRow();

	if (colDiff == 2)
		this->mat[curr->getRow()][curr->getCol() - 1] = ' ';
	if (colDiff == -2)
		this->mat[curr->getRow()][curr->getCol() + 1] = ' ';	// boom
	if (rowDiff == 2)
		this->mat[curr->getRow() - 1][curr->getCol()] = ' ';	//boom 2
	if(rowDiff == -2)
		this->mat[curr->getRow() + 1][curr->getCol()] = ' ';	//boom 3
}

//bool Maze::isAvailableNeighbors()
//{
//	if (!(this->mat[row][col + 1] == '$') && (!isWall()))
//		return true;
//	
//
//	if (!(this->mat[row + 1][col] == '$') && (!isWall()))
//		return true;
//
//	if (!(this->mat[row][col - 1] == '$') && (!isWall()))
//		return true;
//
//	if (!(this->mat[row - 1][col] == '$') && (!isWall()))
//		return true;
//
//}
