#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
#include "Square.h"
using namespace std;

class Maze
{
public:
	Maze() = default;
	Maze(char** mat, int rows, int cols);
	Maze(Maze&& other);
	~Maze();
	void print() const;
	void createStartingMaze(int rows, int cols);
	void markSquare(int row, int col);
	Square** getSquareNeighbors(int row, int col, bool &flag, int &size);
	//bool isAvailableNeighbors(int row, int col);
	void BreakWall(const Square *curr, Square *neighbor);

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
