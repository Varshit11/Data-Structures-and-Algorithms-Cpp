/*  C++ program to count the number of leaf nodes in the tree */

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

int count_leaf_nodes(Node* root){
	if(!root)
		return 0;
	else if(!root->left && !root->right)
		return 1;
	else
		return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);	
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->right = create_node(5);
	root->right->right->left = create_node(6);
	root->right->right->right = create_node(7);
	
	cout<<"The number of leaf nodes are "<<count_leaf_nodes(root)<<endl;
	return 0;
}

