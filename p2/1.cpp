#include <iostream>
using namespace std;

class Queue {
private:

	int queue[1000];
	int rear = -1;
	int front = -1;

	int size = 1000;

public:

	bool IsEmpty()
	{
		if (rear == front)
		{
			return true;
		}

		else false;
	}

	bool IsFull()
	{
		if (rear == (size - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Enqueue(int value)
	{

		if (!IsFull())
		{
			rear++;
			queue[rear] = value;

		}
	}

	int Dequeue()
	{
		if (!IsEmpty)
		{
			int f = queue[front + 1];
			front++;
			return f;
		}
	}


	int Peek()
	{
		return queue[front + 1];
	}


	void ReverseQueue()
	{

		int i = (front + 1);
		int j = rear;
		int t;
		while (i < j)
		{
			queue[i] = t;
			queue[i] = queue[j];
			queue[j] = t;
			++i;
			--j;

		}
	}

	void print()
	{
		for (int i = front + 1; i <= rear; ++i)
		{
			cout << queue[i] << "   ";
		}
	}
};

int main()
{
	return 0;
}