#include <iostream>
using namespace std;

class Array {
private:
	int array[1000];
	int aa = 0;

public:

	void insert(int index, int value)
	{
		for (int i = (aa - 1); i >= index; i--)
		{
			array[i + 1] = array[i];
		}
		array[index] = value;
		aa++;

	}

	int delete_by_value(int value)
	{
		for (int i = 0; i < aa; i++)
		{
			if (array[i] == value)
			{
				int index = i;
				for (int j = i; j < aa; j++)
				{
					array[j] = array[j + 1];
				}
				aa--;
				return index;
			}
		}
	}

	void delete_by_index(int input)
	{
		for (int i = input; i < aa; ++i)
		{
			array[i] = array[i + 1];
		}
		aa--;
	}

	void display()
	{
		for (int i = 0; i < aa; i++)
		{
			cout << array[i] << "   ";
		}
	}

	void append(int value)
	{
		array[aa] = value;
		aa++;
	}

	void reverse()
	{
		int t, ii = (aa - 1);
		for (int i = 0; i < (aa / 2); ++i)
		{
			t = array[i];
			array[i] = array[ii];
			array[ii] = t;
			--ii;
		}
	}

	int search_by_value(int value)
	{
		for (int i = 0; i < aa; ++i)
		{
			if (array[i] == value)
			{
				return i;
			}
		}
	}

};


int main()
{
	return 0;
}