#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *parent;
    vector<Node *> children;
};

Node *addNode(Node *parent, int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->parent = parent;
    parent->children.push_back(newNode);
    return newNode;
};

Node *removeNode(Node *node)
{
    Node *parent = node->parent;
    for (int i = 0; i < parent->children.size(); i++)
    {
        if (parent->children[i] == node)
        {
            parent->children.erase(parent->children.begin() + i);
            break;
        }
    }
    return parent;
};

void printNodes(Node *node)
{
    cout << node->key << " ";
    for (int i = 0; i < node->children.size(); i++)
    {
        printNodes(node->children[i]);
    }
}

int main()
{
    Node *root = new Node();
    root->key = 1;
    root->parent = NULL;
    Node *node1 = addNode(root, 2);
    Node *node2 = addNode(root, 3);
    Node *node3 = addNode(root, 4);
    printNodes(root);
    cout << endl;
    removeNode(node1);
    printNodes(root);
}