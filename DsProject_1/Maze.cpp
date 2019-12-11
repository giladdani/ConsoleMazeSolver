#include "Maze.h"

// c'tor
Maze::Maze(char** mat, int rows, int cols) : mat(mat), rows(rows), cols(cols) {}

// move c'tor
//Maze::Maze(Maze&& other)
//{
//	this->mat = other.mat;
//	this->rows = other.rows;
//	this->cols = other.cols;
//
//	other.mat = nullptr;
//}

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

// Getters
int Maze::getRows()	const
{
	return this->rows;
}
int Maze::getCols() const
{
	return this->cols;
}

// Setters
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
void Maze::markVisited(int row, int col)
{
	this->mat[row][col] = VISITED;
}

// create a starting maze template
void Maze::createStartingMaze(int rows, int cols)
{
	this->mat = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		this->mat[i] = new char[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			if (i % 2 == 0)
				this->mat[i][j] = WALL;
			else
			{
				if (j % 2 == 0)
					this->mat[i][j] = WALL;
				else
					this->mat[i][j] = EMPTY;
			}
		}
		this->mat[i][cols] = '\0';
	}
	this->mat[1][0] = EMPTY;					// maze start
	this->mat[rows - 2][cols - 1] = EMPTY;	// maze exit
}

// returns an array of Points that are the 'Second neighbors' of the given coordinate 
Point** Maze::getAvailableNeighbors(int row, int col, bool &hasAvailableNeighbors, int& size) const
{
	size = 0;
	Point** neighbors = new Point*[4];
	
	// these if statments also filter "visited" neighbors because they look for space only (and not $)

	// right neighbor
	if (col + 2 < this->getCols() && (this->mat[row][col + 2] == ' '))
	{
		neighbors[size] = new Point(row, col + 2);
		hasAvailableNeighbors = true;
		size++;
	}

	// down neighbor
	if (row + 2 < this->getRows() && (this->mat[row + 2][col] == ' '))
	{
		neighbors[size] = new Point(row + 2, col);
		hasAvailableNeighbors = true;
		size++;
	}

	// left neighbor
	if ((col - 2 > 0) && (this->mat[row][col - 2] == ' '))
	{
		neighbors[size] = new Point(row, col - 2);
		hasAvailableNeighbors = true;
		size++;
	}
	
	// up neighbor
	if ((row - 2 > 0) && (this->mat[row - 2][col] == ' '))
	{
		neighbors[size] = new Point(row - 2, col);
		hasAvailableNeighbors = true;
		size++;
	}
	return neighbors;
}

// marks s space in between the given Point and it's neighbor
void Maze::BreakWall(const Point* curr, const Point* neighbor)
{
	int colDiff = curr->getCol() - neighbor->getCol();
	int rowDiff = curr->getRow() - neighbor->getRow();

	// left neighbor
	if (colDiff == 2)
		this->mat[curr->getRow()][curr->getCol() - 1] = ' ';
	// right neighbor
	if (colDiff == -2)
		this->mat[curr->getRow()][curr->getCol() + 1] = ' ';
	// up neighbor
	if (rowDiff == 2)
		this->mat[curr->getRow() - 1][curr->getCol()] = ' ';
	// down neighbor
	if(rowDiff == -2)
		this->mat[curr->getRow() + 1][curr->getCol()] = ' ';
}
