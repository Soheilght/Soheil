#include <iostream>
using namespace std;

class QueueStack {
private:
	int stack_1[1000];
	int stack_2[1000];
	int top_1 = -1;
	int top_2 = -1;
	int size = 1000;

public:

	bool IsEmpty_1()
	{
		if (top_1 == -1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool IsFull_1()
	{
		if (top_1 == (size - 1))
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool IsEmpty_2()
	{
		if (top_2 == -1)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

	bool IsFull_2()
	{
		if (top_2 == (size - 1))
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

		if (!IsEmpty_2())
		{
			int j = 0;
			for (int i = top_2; i >= 0; i--)
			{
				stack_1[j] = stack_2[i];
				++j;
			}
			top_1 = top_2;
			top_2 = -1;
		}
		if (!IsFull_1())
		{
			top_1++;
			stack_1[top_1] = value;
		}
	}

	int Dequeue()
	{
		if (!IsEmpty_1())
		{
			int j = 0;
			for (int i = top_1; i >= 0; i--)
			{
				stack_2[j] = stack_1[i];
				j++;
			}
			top_2 = top_1;
			top_1 = 0;
		}

		if (!IsEmpty_2())
		{
			int t = stack_2[top_2];
			top_2--;
			return t;
		}
	}


	void Print()
	{
		if (!IsEmpty_1())
		{
			int j = 0;
			for (int i = top_1; i >= 0; i--)
			{
				stack_2[j] = stack_1[i];
				j++;
			}
			top_2 = top_1;
			top_1 = 0;
		}

		if (!IsEmpty_2())
		{
			for (int i = top_2; i >= 0; i--)
			{
				cout << stack_2[i] << "  ";
			}
		}
	}


};


int main()
{

	return 0;
}