#include <iostream>
using namespace std;


class CircularLinkidList {

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
			} while (current != first);

			first->next = prev;
			first = prev;
		}
	}
	int Peek()
	{
		return first->date;
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

class Queue : public CircularLinkidList {

public:

	void Enqueue(int x)
	{
		InsertAtEnd(x);
	}

	int Dequeue()
	{
		RemoveAtBegin();
	}

	int Peek()
	{
		CircularLinkidList::Peek;
	}

	void ReverseQueue()
	{
		Invert();
	}

	bool IsEmpty()
	{
		CircularLinkidList::IsEmpty;
	}

};

int main()
{
	return 0;
}