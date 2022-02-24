#include<iostream>
using namespace std;

struct Node{
    public:
        int data;
        Node *next;
    public:
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

struct Queue{
    public:
        Node *front;
        Node *rear;
    public:
        Queue(){
            front = NULL;
            rear = NULL;
        }
        void enqueue(int data){
            Node *newNode = new Node(data);
            if(front == NULL){
                front = newNode;
                rear = newNode;
                return;
            }
                rear->next = newNode;
                rear = newNode;
        }
        void dequeue(){
            if(front == NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
                Node *temp = front;
                front = front->next;
                delete temp;
        }
        void display(){
            if(front == NULL){
                cout<<"Queue is empty"<<endl;
                return;
            }
                Node *temp = front;
                while(temp != NULL){
                    cout<<temp->data<<" ";
                    temp = temp->next;
                }
                cout<<endl;
        }
};

int main(){
    Queue *q = new Queue();
    q->enqueue(10);
    q->dequeue();
    q->display();
    return 0;
}
