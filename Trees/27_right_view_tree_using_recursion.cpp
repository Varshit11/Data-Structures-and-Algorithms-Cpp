/* C++ program to print the right view of binary tree using recursion */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
int max_level = INT_MIN;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void right_view(Node* root, int level){
	if(!root)
		return;
	if(max_level < level){
		cout<<root->data<<" ";
		max_level = level;
	}
	right_view(root->right, level+1);
	right_view(root->left, level+1);
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->left->left = create_node(5);
	root->left->left->left->left = create_node(6);
	root->right->right = create_node(7);
	
	cout<<"The right view of the tree is "<<endl;
	right_view(root, 1); // should display 1 3 7 5 6
	return 0;
}

