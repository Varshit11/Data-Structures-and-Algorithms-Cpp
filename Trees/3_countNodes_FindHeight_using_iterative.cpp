/* C++ program to implement the following functions - 
1. Count the nodes in the binary tree.
2. Find the height of the binary tree 
Implement this without recursion */

#include<iostream>
#include<queue>
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

int* count_nodes_height(Node* root, int* arr){
	queue <Node*> q;
	q.push(root);
	
	while(true){
		int d = q.size();
		arr[1]+=d;
		if(d == 0)
			return arr;
		else
			arr[0]++; // increment height
		
		while(d-- > 0){
			Node* temp = q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			q.pop();
		}
	}
}

int main(){
	root = create_node(1);
	root->left = create_node(3);
	root->right = create_node(2);
	root->left->left = create_node(4);
	root->left->right = create_node(5);
	root->left->right->right = create_node(6);
	root->right->left = create_node(7);
	
	int arr[2] = {-1,0}; // arr[0] will store height, and arr[1] will store count
	count_nodes_height(root, arr);
	cout<<"The number of nodes in binary tree are "<<arr[1]<<endl; // display 7
	cout<<"The height of the tree is "<<arr[0]<<endl; // display 3
	
	return 0;
}

