#include "Stack.h"

// c'tor
Stack::Stack()
{
	this->top = NULL;
}

// d'tor
Stack::~Stack()
{
	MakeEmpty();
}

// cleans the stack out of any values
void Stack::MakeEmpty()
{
	ListNode* curr = this->top;
	while (curr != NULL)
	{
		curr = this->top->getNext();
		delete this->top;
		top = curr;
	}
}

// returns true if the stack is empty
bool Stack::IsEmpty() const
{
	if (this->top == NULL)
		return true;
	return false;
}

// creates and inserts a new point to the stack by given row and column
void Stack::Push(int row, int col)
{
	Point* point = new Point(row, col);
	ListNode* newNode = new ListNode(point, this->top);
	this->top = newNode;
}

// inserts point to stack
void Stack::Push(ListNode* newNode)
{
	this->top = newNode;
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
		ListNode* temp = this->top;
		this->top = this->top->getNext();
		return temp;
	}
}

// returns the top of the stack
const ListNode* Stack::Top()
{
	return this->top;
}