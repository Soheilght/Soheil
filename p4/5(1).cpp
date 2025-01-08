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

class Queue : public list {

public:

	void Enqueue(int x)
	{
		InsertAtEnd(x);
	}

	int Dequeue()
	{
		RemoveNodeAtBigin();
	}

	int Peek()
	{
		list::Peek;
	}

	void ReverseQueue()
	{
		Invert();
	}

	bool IsEmpty()
	{
		list::IsEmpty;
	}

};

int main()
{
	return 0;
}