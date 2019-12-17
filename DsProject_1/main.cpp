/* Hello and welcome! this program solves a given maze and outputs it to the console- showing its
	exacts steps through the process.
There are 2 option to choose from (each option accepts a maximum of 25 rows and 80 columns):

1) Create your maze- The user is creating a maze as he enters each row. with '*' he marks a "wall" and with a space he marks 
	an open space where
	that can be stepped on.
	Once picked, the user enters the number of rows, then the number of columns, then the maze itself row by row.
	the user must only enter valid rows: the first ad last rows must all be Walls and the (1,0) and (1 before lastrow, last column) blocks
	must be an empty space.
2) Generate maze- The program generates a random maze by number of rows and columns given by the user.
	Once this option is picked, the user enters the numbers of rows, then the number of columns. The program will then create a
	random maze for him. In this option the user MUST enter Odd number of rows and columns.

After a maze is created, either by user or randomly generated, the program will solve the(if possible) and mark every block it went
through with a '$' symbol.
Have fun!
*/

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Maze.h"
#include "Stack.h"
#include "Queue.h"

// Global functions
void initMenu();
void createYourMaze(Maze& maze);
bool validateRow(char*& tempRow, int rows, int cols, int rowIndex);
void generateMaze(Maze& maze);
bool SolveMaze(Maze& maze);

// Consts
const int MAX_COLS = 80;
const int MAX_ROWS = 25;
const char OPTION_1 = '1';
const char OPTION_2= '2';

// Main
int main()
{
	srand((unsigned)time(NULL));
	initMenu();
}

// Menu
void initMenu()
{
	Maze maze;
	char choice;
	bool isSolved;

	cout << "Maze: 1) From input 2) Random" << endl;
	cin >> choice;

	// validate chosen option
	while (choice != OPTION_1 && choice != OPTION_2)
	{
		cin >> choice;
	}

	// option 1 - Enter your own maze
	if (choice == OPTION_1)
	{
		createYourMaze(maze);
	}

	// option B - Generate random maze
	if (choice == OPTION_2)
	{
		generateMaze(maze);
	}

	// solve the maze
	isSolved = SolveMaze(maze);
	if (isSolved)
		maze.print();
	else
		cout << "no solution";
}

// craete your maze
void createYourMaze(Maze& maze)
{
	int rows, cols;
	cin >> rows;

	// input validation
	if ((rows > MAX_ROWS) || (rows < 1))
	{
		cout << "invalid input";
		exit(1);
	}
	cin >> cols;
	if ((cols > MAX_COLS) || (cols < 1))
	{
		cout << "invalid input";
		exit(1);
	}

	maze.setCols(cols);
	maze.setRows(rows);

	char** mat = new char*[rows];
	cin.ignore();

	// we use a temporary string to validate user row input before we store it in the maze
	char* tempRow = new char[cols + 1];
	
	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		cin.getline(tempRow, cols + 1);
		if (validateRow(tempRow, rows, cols, rowIndex))	// if all is valid- insert row into maze
			mat[rowIndex] = _strdup(tempRow);
		else
		{
			cout << "invalid input";
			exit(1);
		}
	}
	
	maze.setMat(mat);
}

// validate row entered by user
bool validateRow(char*& tempRow, int rows, int cols, int rowIndex)
{
	// validate row length
	if (strlen(tempRow) != cols)
		return false;

	// validate left wall
	if (rowIndex != 1 && tempRow[0] != Point::WALL)
		return false;

	// validate right wall
	if (rowIndex != rows - 2 && tempRow[cols - 1] != Point::WALL)
		return false;

	// validate maze entrance
	if ((rowIndex == 1) && (tempRow[0] != Point::EMPTY))
		return false;

	// validate maze exit
	if ((rowIndex == rows - 2) && (tempRow[cols - 1] != Point::EMPTY))
		return false;

	// validate row values input
	for (int i = 0; i < cols; i++)
	{
		if (tempRow[i] != Point::EMPTY && tempRow[i] != Point::WALL)
			return false;
		// validate upper and lower wall
		if ((rowIndex == 0 || rowIndex == rows - 1) && tempRow[i] != Point::WALL)
			return false;
	}
	return true;
}

// generate random maze
void generateMaze(Maze& maze)
{
	int rows, cols;
	cin >> rows;

	// input validation
	if ((rows > MAX_ROWS) || (rows < 1) || ((rows % 2) != 1))
	{
		cout << " Error";
		exit(1);
	}
	cin >> cols;
	if ((cols > MAX_COLS) || (cols < 1) || ((cols % 2) != 1))
	{
		cout << " Error";
		exit(1);
	}

	maze.setCols(cols);
	maze.setRows(rows);

	Point** currNeighbors;
	int randNeighbor, numOfNeighbors, currRow, currCol;
	ListNode* currPointNode;
	Stack mazeStack;

	// create the starting maze template
	maze.createStartingMaze(maze.getRows(), maze.getCols());
	mazeStack.Push(1, 1);

	while (!mazeStack.IsEmpty())
	{
		currPointNode = mazeStack.Pop();

		currRow = currPointNode->getPoint()->getRow();
		currCol = currPointNode->getPoint()->getCol();

		// mark current point as visited
		maze.markVisited(currRow, currCol);

		// get the current point's available neighbors
		currNeighbors = maze.getAvailableNeighbors(currRow, currCol, numOfNeighbors, 2);
		if (numOfNeighbors > 0)
		{
			// choose random neighbor
			randNeighbor = rand() % numOfNeighbors;

			// delete the wall between current point and chosen neighbor
			maze.BreakWall(currPointNode->getPoint(), currNeighbors[randNeighbor]);

			// return the current point AND the chosen neighbor to the stack
			mazeStack.Push(currPointNode);
			mazeStack.Push(currNeighbors[randNeighbor]->getRow(), currNeighbors[randNeighbor]->getCol());
		}
	}
	maze.cleanVisited();	// finished creating maze and now ready for solving- remove any left 'visited' $ signs
}

// solves given maze
bool SolveMaze(Maze& maze)
{
	int mazeRows = maze.getRows();
	int mazeCols = maze.getCols();
	int queueMaxSize = (2 + (mazeRows - 2) * (mazeCols - 2));	// calculate maximum size
	Queue queue(queueMaxSize);
	Point** currNeighbors;
	Point* currPoint;
	int size, i;

	queue.EnQueue(1, 0);
	while (!queue.IsEmpty())
	{
		currPoint = queue.DeQueue();
		maze.markVisited(currPoint->getRow(), currPoint->getCol());

		if ((currPoint->getRow() == mazeRows - 2) && (currPoint->getCol() == mazeCols - 1))
			return true;	// maze solved!
		else
		{
			currNeighbors = maze.getAvailableNeighbors(currPoint->getRow(), currPoint->getCol(), size, 1);
			for (i = 0; i < size; i++)
			{
				queue.EnQueue(currNeighbors[i]);
			}
		}
	}

	return false;	// if we got here- maze is not solvable :(
}