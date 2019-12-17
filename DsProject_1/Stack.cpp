#include "Stack.h"

// c'tor
Stack::Stack()
{
	top = NULL;
}

// d'tor
Stack::~Stack()
{
	MakeEmpty();
}

// cleans the stack out of any values
void Stack::MakeEmpty()
{
	ListNode* curr = top;
	while (curr != NULL)
	{
		curr = top->getNext();
		delete top;
		top = curr;
	}
}

// returns true if the stack is empty
bool Stack::IsEmpty() const
{
	if (top == NULL)
		return true;
	return false;
}

// creates and inserts a new point to the stack by given row and column
void Stack::Push(int row, int col)
{
	Point* point = new Point(row, col);
	ListNode* newNode = new ListNode(point, top);
	top = newNode;
}

// inserts point to stack
void Stack::Push(ListNode* newNode)
{
	top = newNode;
}

// deletes and returns top of stack
ListNode* Stack::Pop()
{
	if (IsEmpty())
	{
		cout << "stack is empty" << endl;
		return NULL;
	}
	else
	{
		ListNode* temp = top;
		top = top->getNext();
		return temp;
	}
}

// returns the top of the stack
const ListNode* Stack::Top()
{
	return top;
}