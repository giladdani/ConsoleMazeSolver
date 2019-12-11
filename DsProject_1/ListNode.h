#ifndef __LISTNODE_H
#define __LISTNODE_H

#include "Point.h"

class ListNode
{
public:
	ListNode(const Point* point, ListNode* next);
	~ListNode();

	// Getters
	ListNode* getNext() const;
	const Point* getPoint() const;


private:
	const Point* point;
	ListNode* next;
};

#endif