#include "Queue.h"

Queue::Queue(int size)
{
	this->arr = new Point*[size];
	this->currSize = 0;
}

Queue::~Queue()
{
	for (int i = 0; i < this->currSize; i++)
	{
		delete arr[i];
	}
	delete[]arr;
}
