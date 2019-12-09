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
bool Stack::IsEmpty()
{
	if (this->top == NULL)
		return true;
	return false;
}

void Stack::Push(int row, int col)
{
	Square* square = new Square(row, col);
	ListNode* newNode = new ListNode(square, this->top);
	this->top = newNode;
}

void Stack::Push(ListNode* newNode)
{
	this->top = newNode;
}

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

ListNode* Stack::Top()
{
	return this->top;
}