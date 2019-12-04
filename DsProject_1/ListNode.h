#ifndef __LISTNODE_H
#define __LISTNODE_H

#include "Square.h"

class ListNode
{
public:
	ListNode(Square square, ListNode* next);
	~ListNode();
	// GETTERS SETTERS

private:
	Square square;
	ListNode* next;
};

#endif