/* C++ program to convert binary tree into doubly linked list. 
The doubly linked list order will be inorder traversal of the list and 
no extra space should be used other than the space of tree */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
Node* head = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void tree_to_DLL(Node* root){
	if(!root)
		return;
	tree_to_DLL(root->right); // traverse right 
	root->right = head; // we are inserting the node at beginning in DLL.
	
	if(head)
		head->left = root; // insert at beginning code continue
	
	head = root; // change head to new node as it is inserted in beginning
	tree_to_DLL(root->left);
}

void traverse_DLL(){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->right;
	}
}

int main(){
	root = create_node(2);
	root->left = create_node(3);
	root->right = create_node(4);
	root->left->left = create_node(5);
	root->left->right = create_node(6);
	root->right->right = create_node(7);
	
	tree_to_DLL(root);
	cout<<"The forward pass of doubly linked list is "<<endl;
	traverse_DLL();
	
	return 0;
}

