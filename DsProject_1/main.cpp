#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "Maze.h"
#include "Stack.h"

void initMenu();
void cleanBuffer();
void createYourMaze(Maze& maze);
void generateMaze(Maze& maze);

const int MAX_COLS = 80;
const int MAX_ROWS = 25;
const char OPTION_A = 'A';
const char OPTION_B = 'B';

int main()
{
	initMenu();

	/*srand((unsigned)time(NULL));		// example for using 'rand()'
	int i = rand() % 4;*/
}

// Main Menu
void initMenu()
{
	Maze maze;
	char choice;
	int rows, cols;

	cout << "Choose an option: (A or B)" << endl <<
		"A) Create your own new maze" << endl <<
		"B) Generate random maze" << endl;
	cin >> choice;

	// validate choice
	while (choice != OPTION_A && choice != OPTION_B)
	{
		cout << "Please choose a valid option" << endl;
		cin >> choice;
	}

	cout << "Enter number of rows(max 25): ";
	cin >> rows;
	while (rows > MAX_ROWS)
	{
		cout << "Please enter a valid input: ";
		cin >> rows;
	}
	cout << "Enter number of cols(max 80): ";
	cin >> cols;
	while (cols > MAX_COLS)
	{
		cout << "Please enter a valid input: ";
		cin >> cols;
	}

	maze.setCols(cols);
	maze.setRows(rows);

	if (choice == OPTION_A)
	{
		createYourMaze(maze);
	}
	if (choice == OPTION_B)
	{
		generateMaze(maze);
	}
	cout << endl;
	maze.print();		// print maze (for testing)
}

// craete your maze
void createYourMaze(Maze& maze)
{
	int rows = maze.getRows();
	int cols = maze.getCols();
	char** mat = new char*[rows];
	cin.ignore();
	
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new char[cols + 1];	// leave space for \0
		cout << "Enter the " << i + 1 << " row: " << endl;
		cin.getline(mat[i], cols + 1);
		//mat[i][cols + 2] = '\0';
	}

	maze.setMat(mat);
}

// generate maze
void generateMaze(Maze& maze)
{
	int rows = maze.getRows();
	int cols = maze.getCols();

	maze.createStartingMaze(rows, cols);

	Square** neighbors;
	int randomNeighbor, size;
	bool flag, completed = false;
	ListNode* curr;
	Stack mazeStack;
	mazeStack.Push(1, 1);
	while (!mazeStack.IsEmpty() && !completed)
	{
		flag = false;
		curr = mazeStack.Pop();
		int row = curr->getSquare()->getRow();
		int col = curr->getSquare()->getCol();
		maze.markSquare(row, col);

		neighbors = maze.getSquareNeighbors(row, col, flag, size);
		if (flag)
		{
			srand((unsigned)time(NULL));
			randomNeighbor = rand() % size;
			maze.BreakWall(curr->getSquare(), neighbors[randomNeighbor]);
		}
		mazeStack.Push(curr);
		mazeStack.Push(neighbors[randomNeighbor]->getRow(), neighbors[randomNeighbor]->getCol());
		if ((mazeStack.Top()->getSquare()->getRow == maze.getRows() - 2) && (mazeStack.Top()->getSquare()->getCol == maze.getCols() - 2))
			completed = true;

		/*if (maze.isAvailableNeighbors(row, col))
		{
			

			

		}*/
	}
	cout << "maze is completed (notice: it will destroyed when we exit init maze function!!!!!!!!!!";
}

// cleans buffer out of any left inputs
void cleanBuffer()
{
	int c;
	do
	{						// THIS WHILE STYLE IS NOT GOOD :(
		c = getchar();
	} while (c != EOF && c != '\n');
}