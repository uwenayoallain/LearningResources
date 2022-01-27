#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;

public:
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

class LinkedList
{
public:
	Node *head;

public:
	LinkedList()
	{
		head = NULL;
	}
	void addNewNode(int data)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node *temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void display()
	{
		if (head == NULL)
		{
			cout << "Empty list" << endl;
			return;
		}
		Node *newNode = head;
		while (newNode != NULL)
		{
			cout << newNode->data << endl;
			newNode = newNode->next;
		}
	}
	void insertAt(int data, int position)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			return;
		}
		Node *temp = head;
		int size = 0;
		while (temp->next != NULL)
		{
			temp = temp->next;
			size++;
		}
		if ((position > size + 1) || (position < 1))
		{
			cout << "Invalid position " << position << endl;
			return;
		}
		if (position == 1)
		{
			newNode->next = head;
			head = newNode;
			return;
		}
		Node *prev = head;
		for (int i = 1; i < position - 1; i++)
		{
			prev = prev->next;
		}
		newNode->next = prev->next;
		prev->next = newNode;
	}
};

int main()
{

	LinkedList list;
	list.addNewNode(2);
	list.addNewNode(3);
	list.addNewNode(4);
	list.addNewNode(5);
	list.insertAt(6, 2);
	cout << "Linked list is: " << endl;
	list.display();
}
