#ifndef __STACK_H
#define __STACK_H

#include "ListNode.h"

class Stack
{
public:
	Stack();	//ctor
	~Stack();	// dtor

	void MakeEmpty();
	bool IsEmpty();			// bool or int?
	void Push(Square* square);	// pointer or not?
	Square* Pop();
	Square* Top();

private:
	ListNode* top;
};

#endif
