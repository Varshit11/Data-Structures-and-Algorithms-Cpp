/* C++ program to print the vertical order traversal of binary tree */
// for hashing we are using multimap
#include<iostream>
#include<map>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
multimap <int, int> m;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void vertical_order(Node* root, int i){
	if(!root)
		return;
	m.insert(pair<int, int> (i, root->data));
	vertical_order(root->left, i-1);
	vertical_order(root->right, i+1);
}

void print_vertical_order(){
	multimap <int, int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++){
		cout<<it->second<<" ";
	}
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->right->left = create_node(4);
	root->right->right = create_node(5);
	root->right->left->left = create_node(6);
	root->right->left->right = create_node(7);
	
	vertical_order(root, 0);
	cout<<"The vertical order of the binary tree is "<<endl;
	print_vertical_order();
	
	return 0;
}

