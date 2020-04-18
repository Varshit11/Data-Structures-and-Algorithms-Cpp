/*C++ program to find lowest common ancestor of 2 nodes in a binary search tree*/

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

int lowest_common_ancestor(Node* root, int d1, int d2){
	if(!root)
		return INT_MIN;
	if(d1 < root->data && d2< root->data)
		return lowest_common_ancestor(root->left, d1, d2);
	else if(d1 > root->data && d2 > root->data)
		return lowest_common_ancestor(root->right, d1, d2);
	else
		return root->data;
}

int main(){
	root = create_node(20);
	root->left = create_node(8);
	root->right = create_node(22);
	root->left->left = create_node(4);
	root->left->right = create_node(12);
	root->left->right->left = create_node(10);
	root->left->right->right = create_node(14);
	
	cout<<"The common ancestor between 10 nd 14 is "<<lowest_common_ancestor(root, 10, 14);
	cout<<"\nThe common ancestor between 4 and 14 is "<<lowest_common_ancestor(root, 4, 14);
	cout<<"\nThe common ancestor between 8 and 12 is "<<lowest_common_ancestor(root, 8, 12);
	cout<<"\nThe common ancestor between 12 and 22 is "<<lowest_common_ancestor(root, 12, 22);
	cout<<"\nThe common ancestor between 20 and 4 is "<<lowest_common_ancestor(root, 20, 4);

	return 0;
}

