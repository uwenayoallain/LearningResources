#include <iostream>

using namespace std;

struct Node
{
public:
    Node *prev;
    int data;
    Node *next;

public:
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};
struct Doubly
{
public:
    Node *head;

public:
    Doubly()
    {
        this->head = NULL;
    }

public:
    int isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void addatBegin(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
            return;
        }
        this->head->prev = newNode;
        newNode->next = this->head;
        this->head = newNode;
    }
    void addToEnd(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
            return;
        }
        Node *temp = this->head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    void inserAfter(Node *node, int data)
    {
        Node *newNode = new Node(data);
        if (node->next == NULL)
        {
            node->next = newNode;
            newNode->prev = node;
            return;
        }
        Node *temp = node->next;
        newNode->prev = node;
        newNode->next = temp;
        node->prev = newNode;
    }
    void addNodeBefore(Node *node, int data){
        Node *newNode = new Node(data);
        if(node->prev == NULL){
            this->head = newNode;
            newNode->next = node;
            node->prev = newNode;
            return;
        }
        Node *temp = node->prev;
        newNode->next = node;
        newNode->prev = temp;
        node->prev = newNode;
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };
};

int main()
{
    Doubly *d = new Doubly();
    d->addatBegin(10);
    d->addatBegin(20);
    d->addatBegin(30);
    d->addToEnd(40);
    d->display();
    return 0;
}
