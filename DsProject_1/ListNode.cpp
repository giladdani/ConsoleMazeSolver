#include "ListNode.h"

//ctor
ListNode::ListNode(Square square, ListNode* next)
{
	this->square = square;
	this->next = next;
}

ListNode::~ListNode()
{
	// wtf?
}

