#ifndef __POINT_H
#define __POINT_H

#include <iostream>
using namespace std;

//const char EMPTY = ' ';
//const char WALL = '*';
//const char VISITED = '$';

class Point
{
public:
	static const char EMPTY = ' ';
	static const char WALL = '*';
	static const char VISITED = '$';

public:
	Point() = default;
	Point(int row, int col);

	// Getters
	int getRow() const;
	int getCol() const;

private:
	int row, col;
};

#endif