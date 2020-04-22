/* C++ program to print the sum of all the left leaf nodes in a binary tree */

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

int sum_of_left_leaves(Node* root){
	int s = 0;
    if(!root)
        return 0;
    if(root->left && !root->left->left && !root->left->right){
        s+= root->left->data;
    }
    return s + sum_of_left_leaves(root->left) + sum_of_left_leaves(root->right);
}

int main(){
	root = create_node(3);
	root->left = create_node(9);
	root->right = create_node(20);
	root->right->left = create_node(15);
	root->right->right = create_node(7);
	
	cout<<"The sum of all the left leaf nodes is "<<sum_of_left_leaves(root);
	return 0;
}


