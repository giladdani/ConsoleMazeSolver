#ifndef __QUEUE_H
#define __QUEUE_H

#include "Point.h"

class Queue
{
public:
	Queue() = delete;
	Queue(int size);
	~Queue();
public:
	void MakeEmpty();
	bool IsEmpty() const;
	const Point* Front() const;
	void EnQueue(Point* newPoint);
	void EnQueue(int row, int col);
	Point* DeQueue();
private:
	Point** arr;
	int maxSize;
	int head, tail;
};

#endif