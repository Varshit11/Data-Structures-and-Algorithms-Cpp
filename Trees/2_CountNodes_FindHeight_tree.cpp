/* C++ program to implement the following functions - 
1. Count the nodes in the binary tree.
2. Find the height of the binary tree */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int count_nodes(Node* root1){
	return !root1 ? 0 : 1+count_nodes(root1->left) + count_nodes(root1->right);
}

int find_height(Node* root1){ // max is the C++ built in function
	return !root1 ? -1 : 1+max(find_height(root1->left), find_height(root1->right));
}

int main(){
	root = create_node(1);
	root->left = create_node(3);
	root->right = create_node(2);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->left->right->right = create_node(6);
	root->right->left = create_node(7);
	
	cout<<"The number of nodes in the tree are "<<count_nodes(root)<<endl; // should display 7
	cout<<"The height of the tree is "<<find_height(root)<<endl; // should display 3
	
	return 0;
}

