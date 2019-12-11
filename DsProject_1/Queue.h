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

private:
	Point** arr;
	int currSize;
};

#endif