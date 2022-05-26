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

Node *genTree(vector<int> arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = addNode(NULL, arr[mid]);
    root->children.push_back(genTree(arr, start, mid - 1));
    root->children.push_back(genTree(arr, mid + 1, end));
    return root;
}

BFSGenTree(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->key << " ";
        for (int i = 0; i < temp->children.size(); i++)
        {
            q.push(temp->children[i]);
        }
    }
}

void printTree(vector<Node *> arr, int start, int end)
{
    if (start > end)
        return;
    int mid = (start + end) / 2;
    cout << arr[mid]->key << " ";
    printTree(arr, start, mid - 1);
    printTree(arr, mid + 1, end);
}

int main()
{
    Node *root = new Node();
    root->key = 1;
    root->parent = NULL;
    Node *node1 = addNode(root, 2);
    Node *node2 = addNode(root, 3);
    Node *node3 = addNode(root, 4);
    Node *node4 = addNode(root, 10);
    Node *node5 = addNode(root, 15);
    Node *node6 = addNode(root, 7);
    BFSGenTree(root);
    // printTree(root->children, 0, root->children.size() - 1);
    cout << endl;
    return 0;
}