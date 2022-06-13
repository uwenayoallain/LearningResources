#include <bits/stdc++.h>
#include <iostream>

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
    if (parent != NULL)
    {
        parent->children.push_back(newNode);
    }
    return newNode;
}

void BFSGenTree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        while (size > 0)
        {
            Node *current = q.front();
            cout << current->key << " ";
            q.pop();
            for (auto children : current->children)
            {
                q.push(children);
            }
            size--;
        }
        cout <<endl;
    }
}

int main()
{
    Node *root = addNode(NULL, 1);

    Node *node1 = addNode(root, 2);
    Node *node2 = addNode(root, 3);

    Node *node3 = addNode(node1, 4);
    Node *node4 = addNode(node1, 5);

    Node *node5 = addNode(node2, 6);
    Node *node6 = addNode(node2, 7);

    Node *node7 = addNode(node3, 8);
    Node *node8 = addNode(node3, 9);

    Node *node9 = addNode(node4, 10);
    Node *node10 = addNode(node4, 11);

    Node *node11 = addNode(node5, 13);
    Node *node12 = addNode(node6, 14);
    BFSGenTree(root);
    return 0;
}