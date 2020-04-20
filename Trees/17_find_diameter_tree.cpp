/* C++ program to find the diameter of the tree */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
int diam = INT_MIN;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int find_diameter(Node* root){
	if(!root)
		return -1;
	int l = find_diameter(root->left);
	int r = find_diameter(root->right);
	diam = max(diam, l+r+2);
	return 1+max(l,r);
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->right->right = create_node(5);
	root->right->right->right = create_node(6);
	root->right->right->right->right = create_node(7);
	root->right->right->left = create_node(8);
	root->right->left = create_node(9);
	root->right->left->left = create_node(10);
	root->right->left->right = create_node(11);
	root->right->left->right->left = create_node(12);
	root->right->left->right->right = create_node(13);
	
	find_diameter(root);
	cout<<"The diameter of this tree is "<<diam<<endl;
	
	// lets make another tree.
	diam = INT_MIN;
	Node* root1 = create_node(1);
	root1->left = create_node(2);
	root1->left->left = create_node(3);
	root1->left->right = create_node(4);
	root1->left->left->left = create_node(5);
	root1->left->left->left->right = create_node(6);
	root1->left->left->left->right->left = create_node(7);
	root1->left->left->left->right->right = create_node(8);
	root1->right = create_node(9);
	root1->right->right = create_node(10);
	root1->right->right->left = create_node(11);
	root1->right->right->right = create_node(12);
	root1->right->right->right->right = create_node(13);
	root1->right->right->right->left = create_node(14);
	
	find_diameter(root1);
	cout<<"The diameter of tree2 is "<<diam<<endl;
	
	return 0;
}

