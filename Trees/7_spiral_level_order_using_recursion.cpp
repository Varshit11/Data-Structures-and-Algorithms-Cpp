/* C++ program for spiral level order traversal using recursion*/

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

int find_height(Node* root){
	return !root ?0:1+max(find_height(root->left), find_height(root->right));
}

void print_spiral(Node* root, int level, int d){
	if(!root)
		return;
	if(level == 1){
		cout<<root->data<<" ";
	}
	else if(level > 1){
		if(d == 1){
			print_spiral(root->left, level-1, d);
			print_spiral(root->right, level-1, d);
		}
		else{
			print_spiral(root->right, level-1, d);
			print_spiral(root->left, level-1, d);
		}
	}
}

void spiral_level_order(Node* root){
	int height = find_height(root), i, d = 0;
	for(i=1;i<=height;i++){
		print_spiral(root, i, d);
		d = !d;
	}
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->right->left = create_node(6);
	root->right->right = create_node(7);
	root->left->left->left = create_node(8);
	root->left->left->right = create_node(9);
	root->left->right->left = create_node(10);
	root->left->right->right = create_node(11);
	root->right->left->left = create_node(12);
	root->right->left->right = create_node(13);
	root->right->right->left = create_node(14);
	root->right->right->right = create_node(15);
	
	cout<<"The spiral level order traversal of the tree is "<<endl;
	spiral_level_order(root);
	
	return 0;	
}

