/* C++ program to print lowest common ancestor in a Binary Tree */

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

Node* lowest_common_ancestor(Node* root, int d1, int d2){
	if(!root)
		return NULL;
	if(root->data == d1 || root->data == d2)
			return root;

	Node* leftsearch = lowest_common_ancestor(root->left, d1, d2);
	Node* rightsearch = lowest_common_ancestor(root->right, d1, d2);
	if(!leftsearch)
		return rightsearch;
	if(!rightsearch)
		return leftsearch;
	
//	if(root->left && root->right)
		return root;
}

int main(){
	Node* temp;
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->left->right->left = create_node(7);
	root->left->right->right = create_node(8);
	root->right->left = create_node(6);
	
	temp = lowest_common_ancestor(root, 7,8);
	if(temp)
		cout<<"The LCA of 7 and 8 is "<<temp->data<<endl;
	else
		cout<<"Either one of the 2 elements is not present in the tree"<<endl;

	temp = lowest_common_ancestor(root, 7,4);
	if(temp)
		cout<<"The LCA of 7 and 4 is "<<temp->data<<endl;
	else
		cout<<"Either one of the 2 elements is not present in the tree"<<endl;
	
	temp = lowest_common_ancestor(root, 2,8);
	if(temp)
		cout<<"The LCA of 2 and 8 is "<<temp->data<<endl;
	else
		cout<<"Either one of the 2 elements is not present in the tree"<<endl;
	
	temp = lowest_common_ancestor(root, 4,6);
	if(temp)
		cout<<"The LCA of 4 and 6 is "<<temp->data<<endl;
	else
		cout<<"Either one of the 2 elements is not present in the tree"<<endl;
	
	return 0;
}

