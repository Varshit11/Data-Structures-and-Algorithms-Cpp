/* C++ program to print level order traversal in spiral form. 
For ex. the first level  elements print in right to left, the second level
elememts print from left to right, 3rd level elements right to left and so on
Implement this without using STL*/
// we will implement stack using linked list
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

class Stack_node{
	public:
		Node* t;
		Stack_node* next;
};

Node* root = NULL;
Stack_node* top1 = NULL;
Stack_node* top2 = NULL;

bool isempty_stack(int d){
	return (d==1) ? top1 == NULL : top2 == NULL;
}

void push(Node* t, int d){
	Stack_node* temp = new Stack_node;
	temp->t = t;
	if(d == 1){
		temp->next = top1;
		top1 = temp;
	}
	else{
		temp->next = top2;
		top2 = temp;
	}
}

Node* find_top(int d){
	if(isempty_stack(d))
		return NULL;
	return (d == 1) ? top1->t : top2->t;
}

void pop(int d){
	Stack_node* temp;
	if(isempty_stack(d))
		return;
	if(d == 1){
		temp = top1;
		top1 = top1->next;
	}else{
		temp = top2;
		top2 = top2->next;
	}
	delete temp;
}

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void spiral_level_order(Node* root){
	int level = 1;
	push(root, 1);
	while(!isempty_stack(1) || !isempty_stack(2)){
		if(level%2 == 1){
			while(!isempty_stack(1)){
				Node* temp = find_top(1);
				cout<<temp->data<<" ";
				if(temp->right)
					push(temp->right, 2);
				if(temp->left)
					push(temp->left, 2);
				pop(1);
			}
		}else{
			while(!isempty_stack(2)){
				Node* temp = find_top(2);
				cout<<temp->data<<" ";
				if(temp->left)
					push(temp->left, 1);
				if(temp->right)
					push(temp->right, 1);
				pop(2);
			}
		}
		level++;
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
	// should display 1 2 3 7 6 5 4 8 9 10 11 12 13 14 15
	spiral_level_order(root);
	
	return 0;	
}

