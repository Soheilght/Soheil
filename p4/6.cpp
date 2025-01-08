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


	int RemonveNodeAtEnd()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else if (first->next == NULL)
		{
			int t = first->date;
			first = NULL;
			return t;
		}
		else
		{
			node* q;
			q = first;
			while (q->next->next != NULL)
			{
				q = q->next;
			}
			int t = q->next->date;
			delete q->next;
			q->next = NULL;
			return t;
		}
	}
	int Peek()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		node* q;
		q = first;
		while (q->next != NULL)
		{
			q=q->next;
		}
		return q->date;

    }

	bool IsEmpty()
	{
		if (first == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class stack :public list {
public:

	void push(int x)
	{
		InsertAtEnd(x);
	}

	int pop()
	{
		RemonveNodeAtEnd();
	}

	int Peek()
	{
		list::Peek();
	}

	bool IsEmpty()
	{
		list::IsEmpty();
	}
};

int main()
{
	return 0;
}