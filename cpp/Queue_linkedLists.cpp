#include <iostream>
using namespace std;
// a class to implement Queue using linked lists
class Queue
{
    struct node
    {
        int data;
        node *next;
    };
    node *front, *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }
    void enqueue(int x)
    {
        node *temp = new node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL)
            front = rear = temp;
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue()
    {
        if (front == NULL)
            cout << "Queue is empty";
        else
        {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    void display()
    {
        node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    return 0;
}