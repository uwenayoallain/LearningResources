#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *next;
    public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
}

class LinkedLists{
    public:
    Node *head;
    public:
    LinkedLists(){
        head = NULL;
    }
    void addItem(int data){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            return;
        }
        Node *temp = head;
        while(temp != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void display(){
        Node *nextNode = head;
        while(nextNode != NULL){
            cout<<nextNode->data<<endl;
            nextNode = nextNode->next;
        }
    }
}

int main()
{
}