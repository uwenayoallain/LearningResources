// Double ended queue
#include <iostream>
using namespace std;

#define MAX 100

class Deque
{
    int arr[MAX];
    int front;
    int rear;
    int size;

public:
    Deque(int size)
    {
        front = -1;
        rear = 0;
        this->size = size;
    }

public:
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || front == rear + 1)
        {
            cout << "Queue is full" << endl;
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return true;
        }
        return false;
    }

    void insertFront(int data)
    {

        if (isFull())
            return;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if (front == 0)
        {
            front = size - 1;
        }
        else
        {
            front = front - 1;
        }

        arr[front] = data;
    }

    void insertRear(int data)
    {
        if (isFull())
            return;

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }

        else if (rear == size - 1)

            rear = 0;

        else
            rear = rear + 1;

        arr[rear] = data;
    }

    void deleteFromFront()
    {

        if (isEmpty())
            return;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else

            if (front == size - 1)
            front = 0;
        else
            front = front + 1;
    }

    void deleteFromRear()
    {
        if (isEmpty())
            return;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
            rear = size - 1;
        else
            rear = rear - 1;
    }

    void displayAtFront()
    {

        if (isEmpty()) return;
        while(front != -1){
            cout << arr[front] << " ";
            front--;
        }
    }

};

int main()
{
    Deque d(5);
    d.insertFront(1);
    d.insertRear(10);
    d.insertFront(11);
    d.insertRear(16);
    d.insertFront(12);
    d.displayAtFront();
}