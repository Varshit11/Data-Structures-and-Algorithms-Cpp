/* C++ program to merge 2 binary tree. 
Problem link - https://leetcode.com/problems/merge-two-binary-trees/ 
*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root1 = NULL;
Node* root2 = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* merge_trees(Node* root1, Node* root2){
	if(!root1 && !root2)
		return NULL;
	if(!root1)
		return root2;
	if(!root2)
		return root1;
	root1->data += root2->data;
	if(root1 && root2){
		root1->left = merge_trees(root1->left, root2->left);
		root1->right = merge_trees(root1->right, root2->right);
	}
	return root1;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	root1 = create_node(1);
	root1->left = create_node(3);
	root1->right = create_node(2);
	root1->left->left = create_node(5);
	
	root2 = create_node(2);
	root2->left = create_node(1);
	root2->left->right = create_node(4);
	root2->right = create_node(3);
	root2->right->right = create_node(7);
	
	root1 = merge_trees(root1, root2);
	cout<<"The inorder traversal of the merged tree is "<<endl;
	inorder(root1);
	
	return 0;
}


