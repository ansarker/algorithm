#include <iostream>
using namespace std;

class Queue
{
public:
	Queue(int size = 10);		  // constructor
	~Queue() { delete[] values; } // destructor
	bool IsEmpty(void);
	bool IsFull(void);
	bool Enqueue(double x);
	bool Dequeue(double &x);
	void DisplayQueue(void);

private:
	int front;		// front index
	int rear;		// rear index
	int counter;	// number of elements
	int maxSize;	// size of array queue
	double *values; // element array
};
Queue::Queue(int size /* = 10 */)
{
	values = new double[size];
	maxSize = size;
	front = 0;
	rear = -1;
	counter = 0;
}
bool Queue::IsEmpty()
{
	if (counter)
		return false;
	else
		return true;
}
bool Queue::IsFull()
{
	if (counter < maxSize)
		return false;
	else
		return true;
}
bool Queue::Enqueue(double x)
{
	if (IsFull())
	{
		cout << "Error: the queue is full." << endl;
		return false;
	}
	else
	{
		// calculate the new rear position (circular)
		rear = (rear + 1) % maxSize;
		// insert new item
		values[rear] = x;
		// update counter
		counter++;
		return true;
	}
}
bool Queue::Dequeue(double &x)
{
	if (IsEmpty())
	{
		cout << "Error: the queue is empty." << endl;
		return false;
	}
	else
	{
		// retrieve the front item
		x = values[front];
		// move front
		front = (front + 1) % maxSize;
		// update counter
		counter--;
		return true;
	}
}
void Queue::DisplayQueue()
{
	cout << "front -->";
	for (int i = 0; i < counter; i++)
	{
		if (i == 0)
			cout << "\t";
		else
			cout << "\t\t";
		cout << values[(front + i) % maxSize];
		if (i != counter - 1)
			cout << endl;
		else
			cout << "\t<-- rear" << endl;
	}
}

int main(void)
{
	Queue queue(5);
	cout << "Enqueue 5 items." << endl;
	for (int x = 0; x < 5; x++)
		queue.Enqueue(x);
	cout << "Now attempting to enqueue again..." << endl;
	queue.Enqueue(5);
	queue.DisplayQueue();
	double value;
	queue.Dequeue(value);
	cout << "Retrieved element = " << value << endl;
	queue.DisplayQueue();
	queue.Enqueue(7);
	queue.DisplayQueue();
	return 0;
}
