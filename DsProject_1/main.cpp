#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
#include "Maze.h"

void cleanBuffer();
void createYourMaze(Maze& maze);
void generateMaze(Maze& maze);

const int MAX_COLS = 80;
const int MAX_ROWS = 25;

void main()
{
	/*srand((unsigned)time(NULL));		// example for using 'rand()'
	int i = rand() % 4;*/

	Maze maze;
	char choice;

	cout << "Choose an option: (A or B)" << endl <<
			"A) Create your own new maze" << endl <<
			"B) Generate random maze" << endl;
	cin >> choice;
	if (choice != 'A' && choice != 'B')
	{
		// invalid input
		exit(-1);
	}

	if (choice == 'A')
	{
		createYourMaze(maze);
		maze.print();
	}
	if (choice == 'B')
	{
		generateMaze(maze);
	}
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

// craete your maze
void createYourMaze(Maze& maze)
{
	int rows, cols;

	do {
		cout << "Enter number of rows(max 25): ";
		cin >> rows;
	} while (rows > MAX_ROWS);

	do {
		cout << "Enter number of cols(max 80): ";
		cin >> cols;
	} while (cols > MAX_COLS);

	char** mat = new char*;
	
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new char[cols + 1];
		cout << "Enter the " << i + 1 << " row: " << endl;
		cleanBuffer();						// PROBLEM! SOLVE!
		cin.getline(mat[i], cols);
		mat[i][cols + 1] = '\0';
	}

	maze.setMat(mat);
	maze.setRows(rows);
	maze.setCols(cols);
}

// generate maze
void generateMaze(Maze& maze)
{
	int rows, cols;

	do {
		cout << "Enter number of rows(max 25): ";
		cin >> rows;
	} while (rows > MAX_ROWS);

	do {
		cout << "Enter number of cols(max 80): ";
		cin >> cols;
	} while (cols > MAX_COLS);

	// start breaking walls with Stack
}