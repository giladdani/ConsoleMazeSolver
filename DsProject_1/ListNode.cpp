#include "ListNode.h"

// c'tor
ListNode::ListNode(const Point* point, ListNode* next) : point(point)
{
	this->next = next;
}

// d'tor
ListNode::~ListNode()
{
	delete point;
	// delete next?
}

// Getters
ListNode* ListNode::getNext() const
{
	return next;
}
const Point* ListNode::getPoint() const
{
	return point;
}