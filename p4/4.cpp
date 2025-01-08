#include <iostream>
using namespace std;

class list {

private:

	struct node {
		int date;
		node* next;
	};

	node* first = NULL;

public:

	void InsertAtEnd(int x)
	{
		node* p;
		p = new node;
		p->date = x;
		p->next = NULL;
		if (first == NULL)
		{
			first = p;
		}
		else
		{
			node* q;
			q = first;
			while (q->next != NULL)
			{
				q = q->next;
			}
			q->next = p;
		}
	}

	void InsertAtIndex(int x, int index)
	{
		node* p;
		p = new node;
		p->date = x;

		if (index == 0)
		{
			p->next = first;
			first = p;
		}
		else
		{
			node* q;
			q = first;
			for (int i = 0; i < index - 1 && q != NULL; ++i)
			{
				q = q->next;
			}
			p->next = q->next;
			q->next = p;

		}
	}

	

	int RemonveNodeAtIndex(int index)
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else if (index == 0)
		{
			int t = first->date;
			node* q = first;
			first = first->next;
			delete q;
			return t;
		}
		else
		{
			node* q;
			q = first;
			for (int i = 0; i < index - 1 && q->next != NULL; ++i)
			{
				q = q->next;
			}
			int t = q->next->date;
			node* ddd = q->next;
			q->next = q->next->next;
			delete ddd;
			return t;


		}
	}

	void Invert()
	{
		node* prev = NULL;
		node* current = first;
		node* next = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		first = prev;
	}

	int DeleteByValue(int x)
	{
		if (first == NULL)
		{
			cout << '!';
			return -1;
		}
		else if (x == first->date)
		{
			node* q = first;
			first = first->next;
			delete q;
			return 0;
		}
		else
		{
			node* q = first;
			node* t = NULL;
			int i = 0;
			while (q->next != NULL)
			{
				t = q;
				q = q->next;
				++i;
				if (q->date == x)
				{
					
					t->next = q->next;
					delete q;
					return i;
				}
			}
			cout << '!';
			return -1;
		}
	}

	void Display()
	{
		if (first == NULL)
		{
			cout << '!';
		}
		else
		{
			node* q = first;
			do
			{
				cout << q->date;
				q = q->next;
			} while (q != NULL);
		}
	}

	int SearchByValue(int x)
	{
		if (first == NULL)
		{
			cout << '!';
			return -1;
		}

		else if (x == first->date)
		{
			return 0;
		}
		else
		{
			node* q = first;
			int i = 0;
			while (q->next != NULL)
			{
				q = q->next;
				++i;
				if (q->date == x)
				{
					return i;
				}
				
			}
		}
	}

};

class array :public list {

public:
	
	void Insert(int index, int value)
	{
		InsertAtIndex(value, index);
	}

	void Delete_By_Index(int inpute)
	{
		RemonveNodeAtIndex(inpute);
	}

	void Append(int value)
	{
		void InsertAtEnd(int x);
	}

	void Reverse()
	{
		Invert();
	}

	int Delete_By_Value(int x)
	{
		DeleteByValue(x);
	}

	void Display()
	{
		list::Display();
	}

	int Search_By_Value(int value)
	{
		SearchByValue(value);
	}
};

int main()
{
	return 0;
}