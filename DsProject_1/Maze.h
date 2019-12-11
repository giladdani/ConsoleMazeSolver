#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include "Point.h"
using namespace std;

const char EMPTY = ' ';
const char WALL = '*';
const char VISITED = '$';

class Maze
{
public:
	Maze() = default;
	Maze(char** mat, int rows, int cols);
	//Maze(Maze&& other);	// move c'tor
	~Maze();

public:
	void print() const;
	void createStartingMaze(int rows, int cols);
	void markVisited(int row, int col);
	Point** getAvailableNeighbors(int row, int col, bool &hasAvailableNeighbors, int &size) const;
	void BreakWall(const Point* curr,const Point* neighbor);

	// Getters
	int getRows()	const;
	int getCols()	const;

	// Setters
	bool setMat(char** mat);
	bool setRows(int rows);
	bool setCols(int cols);

private:
	char** mat;
	int rows, cols;
};

#endif
