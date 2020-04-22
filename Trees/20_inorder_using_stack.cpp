/* C++ program to implement inorder traversal using stack. No recursion */

#include<iostream>
#include<stack>
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

void inorder(Node* root){
	stack <Node*> s;
	while(root || !s.empty()){
		while(root){
			s.push(root);
			root = root->left;
		}
		if(!s.empty()){
			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root = root->right;
		}
	}
}


int main(){
	root = create_node(10);
	root->left = create_node(6);
	root->right = create_node(15);
	root->left->left = create_node(4);
	root->left->right = create_node(7);
	root->left->right->left = create_node(6);
	root->left->right->right = create_node(9);
	root->right->left = create_node(13);
	root->right->right = create_node(20);
	
	cout<<"The inorder traversal of the tree is "<<endl;
	inorder(root);
	return 0;
}

