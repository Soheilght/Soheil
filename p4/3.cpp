#include <iostream>
using namespace std;


class DoublyLinkedList {
private:

	struct node {
		int date;
		node* next;
		node* prev;
	};
	node* first = NULL;
	node* tail = NULL;

public:

	void InsertAtBegin(int x)
	{
		node* p;
		p->date = x;
		p->next = first;
		p->prev = NULL;
		if (first != NULL)
		{
			first->prev = p;
		}
		first = p;
		if (tail == NULL)
		{
			tail = p;
		}
	}

	void InsertAtEnd(int x)
	{
		node* p;
		p->date = x;
		p->next = NULL;
		p->prev = tail;
		if (tail == NULL)
		{
			tail->next = p;
		}
		tail = p;
		if (first == NULL)
		{
			first = p;
		}
	}

	void InsertAtIndex(int x, int index)
	{
		if (index == 0)
		{
			InsertAtBegin(x);
		}

		else
		{
			node* q = first;
			for (int i = 0; i < index - 1 && q->next != NULL; ++i)
			{
				q = q->next;
			}

			if (q == NULL || q->next == NULL)
			{
				InsertAtEnd(x);
			}

			else
			{
				node* p;
				p = new node;
				p->date = x;
				p->next = q->next;
				p->prev = q;
				q->next->prev = p;

			}
		}
	}

	int RemoveAtBegin()
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}
		else
		{
			int date = first->date;
			node* q = first;
			first = first->next;

			if (first != NULL)
			{
				first->prev = NULL;
			}
			else
			{
				tail = NULL;
			}
			delete q;
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
			int date = tail->date;
			node* q = tail;
			tail = tail->prev;

			if (tail != NULL)
			{
				tail->next = NULL;
			}
			else
			{
				first = NULL;
			}
			delete q;
			return date;
		}
	}

	int RemoveAtEnd(int index)
	{
		if (first == NULL)
		{
			cout << "!";
			return -1;
		}

		else if (index == 0)
		{
			RemoveAtBegin();
		}

		else
		{
			node* q = first;
			for (int i = 0; i < index; ++i)
			{
				q = q->next;
			}
			int date = q->date;
			q->prev->next = q->next;
			q->next->prev = q->prev;
			delete q;
			return date;

		}
	}

	void UpdateNode(int x, int index)
	{
		if (first == NULL)
		{
			cout << "!";
			return;
		}
		else
		{
			node* q = first;
			for (int i = 0; i < index; ++i)
			{
				q = q->next;
			}
			q->date = x;
		}
	}

	int SizeOfList()
	{
	
		node* q = first;
		int i = 0;
		while (q->next != NULL)
		{
			q = q->next;
			++i;
		}
		return i;
	}

	void Concatenate(DoublyLinkedList& other)
	{
		if (other.first == NULL)
		{
			return;
		}
		if (first == NULL)
		{
			first = other.first;
			tail = other.tail;
		}
		else
		{
			tail->next = other.first;
			other.first->prev = tail;
			tail = other.tail;
		}
		other.first = other.tail = NULL;
	}

	void Invert()
	{
		node* current = first;
		node* temp = NULL;
		while (current != NULL)
		{
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != NULL)
		{
			first = temp->prev;
		}
	}
};
