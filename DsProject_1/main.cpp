#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "Maze.h"
#include "Stack.h"
#include "Queue.h"

void initMenu();
void createYourMaze(Maze& maze);
void generateMaze(Maze& maze);
void SolveMaze(Maze& maze);

const int MAX_COLS = 80;
const int MAX_ROWS = 25;
const char OPTION_A = 'A';
const char OPTION_B = 'B';

int main()
{
	srand((unsigned)time(NULL));
	initMenu();
}

// Main Menu
void initMenu()
{
	Maze maze;
	char choice;

	cout << "Choose an option: (A or B)" << endl <<
		"A) Create your own new maze" << endl <<
		"B) Generate random maze" << endl;
	cin >> choice;

	// validate chosen option
	while (choice != OPTION_A && choice != OPTION_B)
	{
		cout << "Please choose a valid option" << endl;
		cin >> choice;
	}

	// option A - Enter your own maze
	if (choice == OPTION_A)
	{
		createYourMaze(maze);
	}

	// option B - Generate random maze
	if (choice == OPTION_B)
	{
		generateMaze(maze);
	}

	// for test purposes
	maze.print();

	// solve the maze
	SolveMaze(maze);
}

// craete your maze
void createYourMaze(Maze& maze)
{
	int rows, cols;

	cout << "Enter number of rows(max 25): ";
	cin >> rows;

	while ((rows > MAX_ROWS) || (rows < 1))
	{
		cout << "Rows must be a positive number up to 25, renter rows: ";
		cin >> rows;
	}
	cout << "Enter number of cols(max 80): ";
	cin >> cols;
	while ((cols > MAX_COLS) || (cols < 1))
	{
		cout << "Columns must be a positive number up to 80, renter columns: ";
		cin >> cols;
	}

	maze.setCols(cols);
	maze.setRows(rows);

	char** mat = new char*[rows];
	cin.ignore();
	
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new char[cols + 1];
		cout << "Enter the " << i + 1 << " row: " << endl;
		cin.getline(mat[i], cols + 1);
	}

	maze.setMat(mat);
}

// generate random maze
void generateMaze(Maze& maze)
{
	int rows, cols;

	cout << "Enter odd number of rows(max 25): ";
	cin >> rows;

	while ((rows > MAX_ROWS) || (rows < 1) || ((rows % 2) != 1))
	{
		cout << "Rows must be a positive ODD number up to 25, renter rows: ";
		cin >> rows;
	}
	cout << "Enter odd number of cols(max 80): ";
	cin >> cols;
	while ((cols > MAX_COLS) || (cols < 1) || ((cols % 2) != 1))
	{
		cout << "Columns must be a positive ODD number up to 80, renter columns: ";
		cin >> cols;
	}

	maze.setCols(cols);
	maze.setRows(rows);

	Point** currNeighbors;
	int randNeighbor, numOfNeighbors, currRow, currCol;
	bool hasAvailableNeighbors;
	ListNode* currPointNode;
	Stack mazeStack;

	// create the starting maze template
	maze.createStartingMaze(maze.getRows(), maze.getCols());
	mazeStack.Push(1, 1);

	while(!mazeStack.IsEmpty())
	{
		hasAvailableNeighbors = false;
		currPointNode = mazeStack.Pop();

		currRow = currPointNode->getPoint()->getRow();
		currCol = currPointNode->getPoint()->getCol();

		// mark current point as visited
		maze.markVisited(currRow, currCol);

		// get the current point's available neighbors
		currNeighbors = maze.getAvailableNeighbors(currRow, currCol, hasAvailableNeighbors, numOfNeighbors);
		if (hasAvailableNeighbors)
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
}

// solves given maze
void SolveMaze(Maze& maze)
{
	int queueMaxSize = (maze.getRows()) * (maze.getCols());		// is this we calculate the maximum size?
	Queue queue(queueMaxSize);
	// don't forget the queue is CIRCULAR
}