#ifndef __STACK_H
#define __STACK_H

#include "ListNode.h"

class Stack
{
public:
	Stack();
	~Stack();

	void MakeEmpty();
	bool IsEmpty() const;
	void Push(int row, int col);
	void Push(ListNode* newNode);
	ListNode* Pop();
	const ListNode* Top();

private:
	ListNode* top;
};

#endif
