#ifndef __MAZE_H
#define __MAZE_H

#include <iostream>
using namespace std;

class Maze
{
public:
	Maze() = default;
	Maze(char** mat, int rows, int cols);
	void print();

	// Gettters and Setters
	// Setters
	bool setMat(char** mat);
	bool setRows(int rows);
	bool setCols(int cols);

private:
	char** mat;
	int rows, cols;
};

#endif
