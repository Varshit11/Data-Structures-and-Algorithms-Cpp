/* C++ program to convert a given tree into its sum tree */

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

int convert_sum(Node* root){
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return root->data;
	int i = root->data;
	root->data = convert_sum(root->left) + convert_sum(root->right);
	return i+root->data;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	root = create_node(10);
	root->left = create_node(-1);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(-2);
	
	int h = convert_sum(root);
	cout<<"The inorder traversal of the sum tree is "<<endl;
	inorder(root);
	
	return 0;
}

