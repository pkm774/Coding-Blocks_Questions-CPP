#include <iostream>
#include <algorithm>

class node
{
public:
	int data;
	node *next;
};

// Function to calculate numbers of nodes or length of linked list
int LLlength(node *&head)
{
	int count = 0;
	node *temp = head;
	while (temp != NULL)
	{
		++count;
		temp = temp->next;
	}
	delete temp;
	return count;
}

// Function to print data from nodes of link list
void printLL(node *&head)
{
	node *temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << " --> ";
		temp = temp->next;
	}
	delete temp;
	std::cout << "NULL" << std::endl;
}

// Function to insert element at last, head and tail are passed by reference
void insertATlast(node *&head, node *&tail, int dat)
{
	// creating new node having data and pointer element
	node *n = new node;

	// filling elements of node n
	n->data = dat;
	n->next = NULL;

	// if head and tail pointer holds null then put the adress of n into both
	if (head == NULL && tail == NULL)
	{
		head = n;
		tail = n;
	}
	// if tail pointer is not empty then put the adress of n in tail
	// and change the position of tail to current n;
	else
	{
		tail->next = n;
		tail = n;
	}
}

// normal bubble sorting solution
void bubbleSort(node *&head)
{
	int size = LLlength(head);

	for (int i = 0; i < size; ++i)
	{
		node *temp = head;
		for (int j = 0; j <= size - i - 2;)
		{
			if (temp->data > temp->next->data)
			{
				std::swap(temp->data, temp->next->data);
			}
			++j;
			temp = temp->next;
		}
	}
}

// optimal bubble sorting sorting
void bubbleSort2(node *&head)
{
	for (int i = 0; i < LLlength(head); ++i)
	{
		for (node *temp = head; temp->next != NULL; temp = temp->next)
		{
			if (temp->data > temp->next->data)
			{
				std::swap(temp->data, temp->next->data);
			}
		}
	}
}

// Function for input
// take n size and take n input elements
// input tail wise
void LLinput(node *&head, node *&tail)
{
	int size = 0;
	std::cin >> size;

	for (int i = 0; i < size; ++i)
	{
		int data = 0;
		std::cin >> data;
		insertATlast(head, tail, data);
	}
}

int main()
{
	node *head = NULL;
	node *tail = NULL;

	LLinput(head, tail);

	printLL(head);

	// normal
	// bubbleSort(head);
	// optimal
	bubbleSort2(head);

	printLL(head);

	return 0;
}
