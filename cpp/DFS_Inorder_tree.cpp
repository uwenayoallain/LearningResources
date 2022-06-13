#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		Node * left;
		Node * right;
		Node(int data){
			this->data = data;
			this->left = NULL;
			this->right = NULL;
		}
};
class BinaryTree{
	private:
	 Node * root;
	public:
		BinaryTree(){
			this->root = NULL;
		}
	Node * addNode(Node * current,int data,bool isleft){
		Node * newNode = new Node(data);
		if(current == NULL){
			root = newNode;
		}else{
		 if(isleft){
			current->left = newNode;
		}else{
			current->right = newNode;
		}
	}
	return newNode;
}
	void inorderTraversal(Node *root){
		if(root == NULL) return;
		inorderTraversal(root->left);
		cout << root->data<<" ";
		inorderTraversal(root->right);
		
	}
	void preorderTraversal(Node *root){
		if(root == NULL) return;
		cout << root->data<< " ";
		preorderTraversal(root->left);
		preorderTraversal(root->right);
	}
	
	void postorderTraversal(Node *root){
		if(root == NULL) return;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		cout << root->data<<" ";
	}
};

int main(){
	BinaryTree bt;
	Node * n1 = bt.addNode(NULL,1,false);
	Node * n5 = bt.addNode(n1,5,true);
	Node * n10 = bt.addNode(n1,10,false);
	Node * n3 = bt.addNode(n5,3,true);
	Node * n6 = bt.addNode(n5,6,false);
	Node * n2 = bt.addNode(n3,2,true);
	Node * n16 = bt.addNode(n3,16,false);
	Node * n4 = bt.addNode(n6,4,true);
	Node * n9 = bt.addNode(n10,9,true);
	Node * n11 = bt.addNode(n10,11,false);
	Node * n13 = bt.addNode(n9,13,false);
	Node * n15 = bt.addNode(n11,15,true);
	Node * n92 = bt.addNode(n11,9,false);
//	bt.inorderTraversal(n1);
//	cout<<endl;
//	bt.preorderTraversal(n1);
//	cout<<endl;
	bt.postorderTraversal(n1);
	return 0;
}