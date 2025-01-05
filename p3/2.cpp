#include <iostream>
using namespace std;


class Stack {
private:
	int stack[1000];
	int top = -1;
	int size = 1000;

public:

	bool IsEmpty()
	{
		if (top == -1)
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
		if (top == (size - 1))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Push(int item)
	{
		if (!IsFull)
		{
			top++;
			stack[top] = item;
		}
	}

	int Pop()
	{
		if (!IsEmpty)
		{
			int t;
			t = stack[top];
			top--;
			return t;
		}
	}

	int Peek()
	{
		if (!IsEmpty)
		{
			return stack[top];
		}
	}


};


int main()
{

	return 0;
}