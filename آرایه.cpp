#include <iostream>

using namespace std;

void Insert(int, int);
int Delete_By_Value(int value);
void Delete_By_Index(int input);
void Display();
void Append(int value);
void Reverse(int arr[]);
int Search_By_Value(int Value);


int SIZE = 1000;
int arrr[1000];


int main()
{
	for (int i = 0; i < 1000; ++i)
	{
		arrr[i] = i + 1;
	}
}


void Insert(int index, int value)
{
	arrr[index] = value;
}

int Delete_By_Value(int value)
{
	for (int i = 0; i < 10; ++i)
	{
		if (value == arrr[i])
		{
			for (int j = i; j < (10 - 1); j++)
			{
				arrr[j] = arrr[j + 1];
			}
			SIZE--;
			return i;
		}
	}
}

void Delete_By_Index(int input)
{
	for (int j = input; j < SIZE - 1; ++j)
	{
		arrr[j] = arrr[j + 1];
	}

	SIZE--;
}

void Display()
{
	for (int i = 0; i < SIZE; ++i)
	{
		cout << arrr[i] << " ";
	}
	cout << endl;
}

void Append(int value)
{
	arrr[SIZE - 1] = value;
}


void Reverse(int arr[])
{
	int n = SIZE - 1;
	for (int i = 0; i < SIZE / 2; ++i)
	{
		int m;
		m = arr[i];
		arr[i] = arr[n];
		arr[n] = m;
		--n;

	}
}

int Search_By_Value(int Value) {
	for (int i = 0; i < SIZE; ++i)
	{
		if (arrr[i] == Value)
		{
			return i;
		}
	}
}