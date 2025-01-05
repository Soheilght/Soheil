#include <iostream>
using namespace std;

class CirculareQueue {
private:

	int rear = -1;
	int front = -1;
	int queue[1000];

	int size = 1000;

public:

	bool IsEmpty()
	{
		if (rear == front)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool IsFull()
	{
		if ((rear + 1) % size == front)
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
			rear = (rear + 1) % size;
			queue[rear] = value;
		}
	}

	int Dequeue()
	{
		if (!IsEmpty())
		{
			int t;
			t = queue[front + 1];
			front = (front + 1) % size;
			return t;
		}
	}

	int Peek()
	{
		return queue[front + 1];
	}

	void ReverseQueue()
	{
		int reverse[1000];
		int r = rear;
		int f = ((front + 1) % size);

		if (!IsEmpty())
		{
			int i = ((front + 1) % size);
			int j = 0;
			while (true)
			{
				reverse[j] = queue[i];
				++j;
				i = ((i + 1) % size);
				if (i == rear)
				{
					break;
				}
			}


			for (int i = r; i >= 0; --i)
			{
				queue[f] = reverse[i];
				f = ((front + 1) % size);
			}

			int t = rear;
			rear = front;
			front = t;
		}



	}

	void Print()
	{
		int f = ((front + 1) % size);
		while (true)
		{
			cout << f << "  ";

			if (f == rear)
			{
				break;
			}

			f++;


		}
	}

};