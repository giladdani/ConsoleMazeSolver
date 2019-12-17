#ifndef __MAZE_H
#define __MAZE_H

#include "Point.h"

class Maze
{
public:
	Maze() = default;
	Maze(char** mat, int rows, int cols);
	~Maze();

public:
	void print() const;
	void createStartingMaze(int rows, int cols);
	void markVisited(int row, int col);
	Point** getAvailableNeighbors(int row, int col, int &size, int distance) const;
	void BreakWall(const Point* curr,const Point* neighbor);
	void cleanVisited();

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
