#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include "Maze.h"

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
	int rows, cols;

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
	char** mat = new char*[rows];
	cin.ignore();
	
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new char[cols + 1];	// leave space for \0
		cout << "Enter the " << i + 1 << " row: " << endl;
		cin.getline(mat[i], cols + 1);
		//mat[i][cols + 2] = '\0';
	}

	maze.setCols(cols);
	maze.setRows(rows);
	maze.setMat(mat);
}

// generate maze
void generateMaze(Maze& maze)
{
	int rows, cols;

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
	// start breaking walls with Stack
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