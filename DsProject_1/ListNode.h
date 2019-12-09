#ifndef __LISTNODE_H
#define __LISTNODE_H

#include "Square.h"

class ListNode
{
public:
	ListNode(const Square* square, ListNode* next);
	~ListNode();
	// Getters
	ListNode* getNext() const;
	const Square* getSquare() const;


private:
	const Square* square;
	ListNode* next;
};

#endif