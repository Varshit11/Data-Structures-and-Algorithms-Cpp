/* C++ program for boundary traversal of binary tree. */

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

void print_left_boundary(Node* root){
	if(!root)
		return;
	if(root->left){
		cout<<root->data<<" ";
		print_left_boundary(root->left);
	}
	else if(root->right){
		cout<<root->data<<" ";
		print_left_boundary(root->right);
	}
}

void print_right_boundary(Node* root){
	if(!root)
		return;
	if(root->right){
		print_right_boundary(root->right);
		cout<<root->data<<" ";
	}
	else if(root->left){
		print_right_boundary(root->left);
		cout<<root->data<<" ";
	}
}

void print_leaves(Node* root){
	if(!root)
		return;
	if(!root->left && !root->right)
		cout<<root->data<<" ";
	print_leaves(root->left);
	print_leaves(root->right);
}

void boundary_traversal(Node* root){
	if(!root)
		return;
	cout<<root->data<<" ";
	
	print_left_boundary(root->left);
	
	print_leaves(root->left);
	print_leaves(root->right);
	
	print_right_boundary(root->right);
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->right = create_node(4);
	root->left->right->left = create_node(7);
	root->left->right->right = create_node(8);
	root->right->left = create_node(5);
	root->right->left->left = create_node(9);
	root->right->left->right = create_node(10);
	root->right->right = create_node(6);
	root->right->right->left = create_node(11);
	
	cout<<"The boundary traversal of this binary tree is "<<endl;
	boundary_traversal(root);
	
	return 0;
}


