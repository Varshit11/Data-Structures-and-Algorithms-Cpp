/* C++ program for level order traversal without using STL*/
// we will implement queue using linked list
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

class Queue_node{
	public:
		Node* t;
		Queue_node* next;
};

Node* root = NULL;
Queue_node* front = NULL;
Queue_node* rear = NULL;

bool isempty(){
	return (front == NULL);
}

void enqueue(Node* t){
	Queue_node* temp = new Queue_node;
	temp->t = t;
	temp->next = NULL;
	if(!front){
		front = temp;
		rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

Node* find_front(){
	if(isempty())
		return NULL;
	return front->t;
}

void dequeue(){
	if(isempty())
		return;
	Queue_node* temp = front;
	front = front->next;
	delete temp;
}

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void level_order(Node* root){
	if(!root)
		return;
	enqueue(root);
	while(!isempty()){
		Node* temp = find_front();
		cout<<temp->data<<" ";
		if(temp->left)
			enqueue(temp->left);
		if(temp->right)
			enqueue(temp->right);
		dequeue();
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
	
	cout<<"The level order traversal of the tree is "<<endl;
	level_order(root);
	
	return 0;
}

