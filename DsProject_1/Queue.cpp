#include "Queue.h"

// c'tor
Queue::Queue(int maxSize)
{
	this->maxSize = maxSize;
	arr = new Point*[maxSize];
	head = 1;
	tail = 0;
}
// d'tor
Queue::~Queue()
{
	for (int i = 1; i < tail; i++)
	{
		delete arr[i];
	}
	delete[]arr;
}

// methods
void Queue::MakeEmpty()
{
	head = 1;
	tail = 0;
}

// returns true if the queue is empty
bool Queue::IsEmpty() const
{
	return ((tail + 1) % maxSize) == head;
}

// returns the first Point in the queue's head
const Point* Queue::Front() const
{
	if (IsEmpty())
	{
		cout << "Error:QUEUE EMPTY\n";
		exit(1);
	}
	return arr[head];
}

// inserts a given Point to the back of the queue
void Queue::EnQueue(Point* newPoint)
{
	if ((tail + 2) % maxSize == head)
	{
		cout << "Error:QUEUE FULL\n";
		exit(1);
	}
	tail = (tail + 1) % maxSize;
	arr[tail] = newPoint;

}

// creates and inserts a new Point to the back of the queue by given row and column
void Queue::EnQueue(int row, int col)
{
	if ((tail + 2) % maxSize == head)
	{
		cout << "Error:QUEUE FULL\n";
		exit(1);
	}
	Point* newPoint = new Point(row, col);
	tail = (tail + 1) % maxSize;
	arr[tail] = newPoint;

}

// takes out a Point from the head of the queue
Point* Queue::DeQueue()
{
	if (this->IsEmpty())
	{
		cout << "Error:QUEUE EMPTY\n";
		exit(1);
	}
	Point* temp = arr[head];
	head = (head + 1) % maxSize;
	return temp;
}