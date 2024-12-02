#include <iostream>
using namespace std;

void Enqueue(int x);
int Dequeue();
int Peek();
void ReverseQueue();
bool IsEmpty();
bool IsFull();

int queue[10];
int rear = -1;
int front = -1;

int main()
{
	

}

void Enqueue(int x)
{
	rear = (rear + 1) % 10;
	if (rear == front)
	{
		cout << "queue is full";
		rear--;
	}
	else
	{
		queue[rear] = x;
	}
}

int Dequeue()
{
	if (rear == front)
	{
		cout << "queue is empety";
	}
	else
	{
		int b;
		b = front;
		front = (front + 1) / 10;
		return queue[b];
	}
}

int Peek()
{
	return queue[front+1];
}

void ReverseQueue()
{
	if (rear != front)
	{
		int R = rear;
		int F = front;
		int n;
		int m = (rear - front) / 2;
		for (int i = 1; i < m; i++)
		{
			n = rear;
			rear = front + 1;
			front = n;
			rear--;
			front--;
		}

		rear = F;
		front = R;


		for (int i = front + 1; i = rear; ++i)
		{
			cout << queue[i] << "  ";
		}
	}

	else
	{
		cout << "queue is empety";
	}
}

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
	if ((rear+1)%10 == front)
	{
		return true;
	}

	else
	{
		return false;
	}
}