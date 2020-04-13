/* C++ program to implement stack using linked list */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head;

void push(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

int pop(){
	if(head == NULL){
		cout<<"List is empty so no element popped"<<endl;
		return -1;
	}
	Node* temp = head;
	int data = temp->data;
	head = head->next;
	temp->next = NULL;
	delete temp;
	return data;
}

int main(){
	int j;
	push(1);
	push(2);
	j = pop();
	if(j != -1)
		cout<<j<<" is popped from list"<<endl;
	j = pop();
	if(j != -1)
		cout<<j<<" is popped from list"<<endl;
	j = pop();
	if(j != -1)
		cout<<j<<" is popped from list"<<endl;
	push(3);
	push(4);
	push(5);
	push(6);
	j = pop();
	if(j != -1)
		cout<<j<<" is popped from list"<<endl;
	j = pop();
	if(j != -1)
		cout<<j<<" is popped from list"<<endl;
		
	return 0;
}

