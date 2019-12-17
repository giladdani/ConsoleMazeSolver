#include "Maze.h"

// c'tor
Maze::Maze(char** mat, int rows, int cols) : mat(mat), rows(rows), cols(cols) {}

// d'tor
Maze::~Maze()
{
	if (mat != nullptr)
	{
		for (int i = 0; i < rows; i++)
		{
			delete mat[i];
		}
	}
	delete[]mat;
}

// Getters
int Maze::getRows()	const
{
	return rows;
}
int Maze::getCols() const
{
	return cols;
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
	for (int i = 0; i < rows; i++)
	{
		cout << mat[i] << endl;
	}
}

// marks the given coordinate with '$' as "visited"
void Maze::markVisited(int row, int col)
{
	mat[row][col] = Point::VISITED;
}

// create a starting maze template
void Maze::createStartingMaze(int rows, int cols)
{
	mat = new char*[rows];

	for (int i = 0; i < rows; i++)
	{
		mat[i] = new char[cols + 1];
		for (int j = 0; j < cols; j++)
		{
			if (i % 2 == 0)
				mat[i][j] = Point::WALL;
			else
			{
				if (j % 2 == 0)
					mat[i][j] = Point::Point::WALL;
				else
					mat[i][j] = Point::Point::EMPTY;
			}
		}
		mat[i][cols] = '\0';
	}
	mat[1][0] = Point::EMPTY;					// maze start
	mat[rows - 2][cols - 1] = Point::EMPTY;		// maze exit
}

// returns an array of Points that are the 'Second neighbors' of the given coordinate 
Point** Maze::getAvailableNeighbors(int row, int col, int& size, int distance) const
{
	size = 0;
	Point** neighbors = new Point*[4];

	// these if statments also filter "visited" neighbors because they look for space only (and not $)

	// right neighbor
	if (col + distance < this->getCols() && (mat[row][col + distance] == Point::EMPTY))
	{
		neighbors[size] = new Point(row, col + distance);
		size++;
	}

	// down neighbor
	if (row + distance < this->getRows() && (mat[row + distance][col] == Point::EMPTY))
	{
		neighbors[size] = new Point(row + distance, col);
		size++;
	}

	// left neighbor
	if ((col - distance > 0) && (mat[row][col - distance] == Point::EMPTY))
	{
		neighbors[size] = new Point(row, col - distance);
		size++;
	}

	// up neighbor
	if ((row - distance > 0) && (mat[row - distance][col] == Point::EMPTY))
	{
		neighbors[size] = new Point(row - distance, col);
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
		mat[curr->getRow()][curr->getCol() - 1] = Point::EMPTY;
	// right neighbor
	if (colDiff == -2)
		mat[curr->getRow()][curr->getCol() + 1] = Point::EMPTY;
	// up neighbor
	if (rowDiff == 2)
		mat[curr->getRow() - 1][curr->getCol()] = Point::EMPTY;
	// down neighbor
	if (rowDiff == -2)
		mat[curr->getRow() + 1][curr->getCol()] = Point::EMPTY;
}

// marks any 'visited' point in the maze as 'empty'
void Maze::cleanVisited()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (mat[i][j] == Point::VISITED)
				mat[i][j] = Point::EMPTY;
		}
	}
}
