/* C++ program to trim a binary search tree between a range of values. 
The final tree should have elements in range [L, R] (inclusive). 
Problem link - https://leetcode.com/problems/trim-a-binary-search-tree/
*/

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

Node* trimBST(Node* root, int L, int R){
	if(!root)
		return NULL;
	if(root->data >= L && root->data <= R){
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);
		return root;
	}
	else if(root->data < L)
		return trimBST(root->right, L, R);
	else
		return trimBST(root->left, L, R);
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	root = create_node(3);
	root->left = create_node(0);
	root->right = create_node(4);
	root->left->right = create_node(2);
	root->left->right->left = create_node(1);
	
	root = trimBST(root, 1, 3);
	cout<<"The inorder traversal after trimming the tree is "<<endl;
	// after trimming the traversal should be 1 2 3
	inorder(root);
	
	return 0;
}

