/* C++ program to check if a binary tree follows child sum property */

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

int check_childsum(Node* root){
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	else if(root->data == check_childsum(root->left) + check_childsum(root->right))
		return root->data;
	else
		return -1;
}

int main(){
	root = create_node(20);
	root->left = create_node(12);
	root->right = create_node(8);
	root->left->left = create_node(6);
	root->left->right = create_node(6);
	root->right->left = create_node(3);
	root->right->right = create_node(5);
	root->right->right->left = create_node(5);
	
	int d = check_childsum(root);
	if(d == root->data)
		cout<<"The tree follows childsum property"<<endl;
	else
		cout<<"The tree does not follow childsum property"<<endl;
	return 0;
}

