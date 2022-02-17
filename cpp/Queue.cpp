#include <iostream>

using namespace std;
// implementation of Queue class using structures and arrays
// main functions of a queue are enqueue, dequeue and display
struct Queue
{
    int front, rear, capacity;
    int *queue;

    Queue(int size)
    {
        rear = 0;
        front = 0;
        capacity = size;
        queue = new int;
    }

    void enqueue(int data)
    {
        if (rear == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        queue[rear] = data;
        rear++;
    }

    void dequeue()
    {
        if (front == rear)
            {
                cout << "Queue is empty" << endl;
                return;
        }
        front++;
        return;
    }

    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i < rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << endl;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();
    return 0;
}