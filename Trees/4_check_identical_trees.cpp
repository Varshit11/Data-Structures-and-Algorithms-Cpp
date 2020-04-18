/* C++ program to check if 2 trees are identical or not */

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

bool check_identical(Node* root1, Node* root2){
	if(!root1 && !root2)
		return true;
	else if((!root1 && root2) || (root1 && !root2))
		return false;
	else
		return ((root1->data == root2->data) && check_identical(root1->left, root2->left) &&
				check_identical(root1->right, root2->right));
}

int main(){
	root1 = create_node(1);
	root1->left = create_node(2);
	root1->right = create_node(3);
	root1->left->left = create_node(4);
	root1->left->right = create_node(5);
	root1->right->left = create_node(6);
	root1->right->right = create_node(7);
	
	root2 = create_node(1);
	root2->left = create_node(2);
	root2->right = create_node(3);
	root2->left->left = create_node(4);
	root2->left->right = create_node(5);
	root2->right->left = create_node(6);
	root2->right->right = create_node(7);
	
	if(check_identical(root1, root2)) // should display identical
		cout<<"The 2 trees are identical"<<endl;
	else
		cout<<"The 2 tress are not identical"<<endl;
	
	// now lets make 2 trees different and check again.
	root2->right->right = NULL;
	if(check_identical(root1, root2)) // should display not identical
		cout<<"The 2 trees are identical"<<endl;
	else
		cout<<"The 2 trees are not identical"<<endl;
	
	return 0;
}

