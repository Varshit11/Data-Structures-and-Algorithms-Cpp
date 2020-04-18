/* C++ program to convert a binary tree into its mirror form..*/

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

void swap(Node** t1, Node** t2){
	Node* temp = *t1;
	*t1 = *t2;
	*t2 = temp;
}

void mirror_tree(Node* root){
	if(!root)
		return;
	mirror_tree(root->left);
	mirror_tree(root->right);
	swap(&root->left, &root->right);
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->left = create_node(5);
	root->right->right = create_node(6);
	root->left->left->left = create_node(7);
	root->left->left->right = create_node(8);
	
	cout<<"The inorder of the original tree is "<<endl;
	inorder(root); // display 7 4 8 2 1 5 3 6
	
	mirror_tree(root);
	cout<<"\nThe inorder of the mirror tree is"<<endl;
	inorder(root); // display 6 3 5 1 2 8 4 7
	
	return 0;
}

