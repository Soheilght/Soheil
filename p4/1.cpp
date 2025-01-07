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

	void InsertAtBegin(int x)
	{
		node* p;
		p = new node;
		p->date = x;
		p->next = first;
		first = p;
	}

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
			q->next = p->next;

		}
	}

	void UpdateNode(int x, int index)
	{
		node* q;
		q = first;
		for (int i = 0; i < index && q->next != 0; ++i)
		{
			q = q->next;
		}
		q->date = x;
	}

	int RemoveNodeAtBigin()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			first = first->next;
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

	int  SizeOfList()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			node* q;
			q = first;
			int i = 1;
			while (q->next = NULL)
			{
				q = q->next;
				++i;
			}
			return i;
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

	void Concatenate(list& otherList)
	{
		if (first == NULL)
		{
			first = otherList.first;
		}
		else
		{
			node* q;
			q = first;
			while (q->next != NULL)
			{
				q = q->next;
			}
			q->next = otherList.first;
		}
		otherList.first = NULL;
	}
};

int main()
{
	return 0;
}