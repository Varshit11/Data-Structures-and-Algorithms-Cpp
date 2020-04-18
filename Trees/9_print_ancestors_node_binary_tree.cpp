/* C++ program to print ancestor of a given node in Binary tree */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
int count = 0;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool print_ancestors(Node* root, int data){
	if(!root)
		return false;
	if(root->data == data)
		return true;
	bool i = print_ancestors(root->left, data);
	if(i){
		cout<<root->data<<" ";
		count++;
		return true;
	}	
	bool j = print_ancestors(root->right, data);
	if(j){
		cout<<root->data<<" ";
		count++;
	}
	return j;
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->left->right->left = create_node(7);
	root->left->right->right = create_node(8);
	
	bool i = print_ancestors(root, 10);
	if(!i)
		cout<<"There is no node with this value"<<endl;
	if(i && count == 0)
		cout<<"Since the number found is root so it has no ancestors"<<endl;
		
	return 0;
}

