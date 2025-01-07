#include <iostream>
using namespace std;


class CircularLinkidList {

private:

	struct node{
		int date;
		node* next;
	};
	node* first = NULL;

public:

	void InsertAtBigine(int x)
	{
		node* p;
		p = new node;
		p->date = x;
		if (first == NULL)
		{
			first = p;
			p->next = first;
		}
		else
		{
			node* q;
			q = first;
			while (q->next != first)
			{
				q = q->next;
			}
			q->next = p;
			p->next = first;
			first = p;
		}
	}

	void InsertAtEnd(int x)
	{
		node* p;
		p = new node;
		p->date = x;
		if (first == NULL)
		{
			first = p;
			p->next = first;
		}
		else
		{
			node* q;
			q = first;
			while (q->next != first)
			{
				q = q->next;
			}
			q->next = p;
			p->next = first;
		}
	}

	void InsertAtIndex(int x, int index)
	{
		if (index == 0)
		{
			InsertAtBigine(x);
		}
		else
		{
			node* p;
			p = new node;
			p->date = x;
			node* q = first;
			for (int i = 0; i < index - 1 ; ++i)
			{
				q = q->next;
			}
			p->next = q->next;
			q->next = p;

		}
	}

	int  RemoveAtBegin()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			node* q = first;
			while (q->next != first)
			{
				q = q->next;
			}
			node* todelete = first;
			int date = first->date;
			if (first->next = first)
			{
				first = NULL;
			}
			else
			{
				first = first->next;
				q->next = first;
			}
			delete todelete;
			return date;
		}
	}


	int RemoveAtEnd()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			if (first->next == first)
			{
				int date = first->date;
				first = NULL;
				return date;
			}
			else
			{
				node* q;
				q = first;
				node* prev = NULL;
				while (q->next != first)
				{
					prev = q;
					q = q->next;
				}
				int date = q->date;
				prev->next = first;
				delete q;
				return date;
			}
		}
	}

	int RemoveAtIndex(int index)
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			if (index == 0)
			{
				RemoveAtBegin();
			}
			else
			{
				node* q = first;
				node* prev = NULL;
				for (int i = 0; i < index; ++i)
				{
					prev = q;
					q = q->next;
				}
				int date = q->date;
				prev->next = q->next;
				delete q;
				return date;
			}
		}
	}

	void UpdateNode(int value, int index)
	{
		if (first == NULL)
		{
			cout << "!";
		}
		else
		{
			node* q = first;
			for (int i = 0; i < index; ++i)
			{
				q = q->next;
			}
			q->date = value;
		}
	}

	int SizeOfList()
	{
		if (first == NULL)
		{
			return 0;
		}
		else
		{
			int i = 1;
			node* q = first;
			while (q->next != first)
			{
				q = q->next;
				i++;
			}
			return i;
		}
	}

	void Concatenate(CircularLinkidList& otherList)
	{
		if (!first)
		{
			first = otherList.first;
			return;
		}
		if (!otherList.first)
		{
			return;
		}


		node* q = first;
		while (q->next != first)
		{
			q = q->next;
		}


		node* o = otherList.first;
		while (o->next != otherList.first)
		{
			o = o->next;
		}

		q->next = otherList.first;
		o->next = first;
	}

	void Invert()
	{
		if (!first || first->next == first)
		{
			cout << "!";
		}
		else
		{
			node* prev = NULL;
			node* current = first;
			node* next = NULL;
			do
			{
				next = current->next;
				current->next = prev;
				prev = current;
				current = next;
			}while (current != first);
			
			first->next = prev;
			first = prev;
		}
	}


};

int main()
{
	return 0;
}