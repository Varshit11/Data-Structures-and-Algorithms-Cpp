/* C++ program to find the maximum sum leaf to root path in binary tree */

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

int max_sum_leaf_root(Node* root){
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	return root->data + max(max_sum_leaf_root(root->left), max_sum_leaf_root(root->right));
	// max is the C++ built in function so no need to make extra function
}

int main(){
	root = create_node(2);
	root->left = create_node(3);
	root->right = create_node(4);
	root->left->left = create_node(-4);
	root->left->right = create_node(-100);
	root->left->left->left = create_node(6);
	root->left->left->right = create_node(10);
	root->right->right = create_node(10);
	
	cout<<"The maximum sum leaf to root in the tree is "<<max_sum_leaf_root(root)<<endl;
	return 0;
}

