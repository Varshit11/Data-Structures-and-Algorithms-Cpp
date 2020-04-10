/* C++ program to make doubly linked list using 1 pointer.
we will use the xor operation to solve this problem */

#include<bits/stdc++.h>
#include<inttypes.h>
using namespace std;

typedef struct Node{
	int data;
	struct Node* np;
}Node;

Node* head = NULL;
Node* tail = NULL;
Node* x;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->np = NULL;
	if(head == NULL){
		head = temp;
		tail = temp;
		x = temp->np;
		return;
	}
	tail->np = (Node*)((uintptr_t)(x) ^ (uintptr_t)(temp));
	x = tail;
	tail = temp;
}

void forward_pass(){
	Node* temp = head;
	Node* temp2 = NULL;
	Node* temp3;
	cout<<"The forward pass is"<<endl;
	while(temp!= tail){
		cout<<temp->data<<" ";
		temp3 = temp;
		temp = (Node*)((uintptr_t)(temp->np) ^ (uintptr_t)(temp2));
		temp2 = temp3;
	}
	cout<<tail->data<<endl;
}

void backward_pass(){
	Node* temp = tail;
	Node* temp2 = x;
	Node* temp3;
	cout<<"The backward pass is "<<endl;
	while(temp){
		cout<<temp->data<<" ";
		temp3 = temp;
		temp = (Node*)((uintptr_t)(temp->np) ^ (uintptr_t)(temp2));
		temp2 = temp3;
	}
	cout<<endl;
	
}

int main(){
	add_end(1);
	add_end(2);
	add_end(3);
	add_end(4);
	add_end(5);
	
	forward_pass();	
	backward_pass();
	
	return 0;
}

