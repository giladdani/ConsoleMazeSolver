#include "ListNode.h"

//ctor
ListNode::ListNode(const Square* square, ListNode* next) : square(square)
{
	this->next = next;
}

ListNode::~ListNode()
{
	// wtf?
}

ListNode* ListNode::getNext() const
{
	return this->next;
}
const Square* ListNode::getSquare() const
{
	return square;
}