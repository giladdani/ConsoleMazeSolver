#ifndef __STACK_H
#define __STACK_H

#include "ListNode.h"

class Stack
{
public:
	Stack();	// c'tor
	~Stack();	// d'tor

	void MakeEmpty();
	bool IsEmpty();
	void Push(int row, int col);
	void Push(ListNode* newNode);
	ListNode* Pop();
	ListNode* Top();

private:
	ListNode* top;
};

#endif
