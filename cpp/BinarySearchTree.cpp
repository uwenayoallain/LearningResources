#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        this->root = NULL;
    }
    Node *add_node(Node *root, int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return root;
        }
        if (data < root->data)
        {
            root->left = add_node(root->left, data);
        }
        else
        {
            root->right = add_node(root->right, data);
        }
        return root;
    }
    void inorderTraversal(Node *root)
    {
        if (root == NULL)
            return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }

    void preorderTraversal(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    void postorderTraversal(Node *root)
    {
        if (root == NULL)
            return;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
};

int main()
{
    BinaryTree bt;
    Node *root = NULL;
    root = bt.add_node(root, 10);
    root = bt.add_node(root, 5);
    root = bt.add_node(root, 40);
    root = bt.add_node(root, 3);
    root = bt.add_node(root, 7);
    root = bt.add_node(root, 30);
    root = bt.add_node(root, 100);
    root = bt.add_node(root, 1);
    root = bt.add_node(root, 4);
    root = bt.add_node(root, 6);
    root = bt.add_node(root, 8);
    root = bt.add_node(root, 80);
    root = bt.add_node(root, 200);
    root = bt.add_node(root, 0);
    root = bt.add_node(root, 2);
    root = bt.add_node(root, 70);
    root = bt.add_node(root, 9);
    bt.inorderTraversal(root);
    cout << endl;
    bt.preorderTraversal(root);
    cout << endl;
    bt.postorderTraversal(root);
    cout << endl;
    return 0;
}