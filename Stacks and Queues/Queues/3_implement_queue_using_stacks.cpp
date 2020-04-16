/* C++ program to Implement queue using stacks 
We will use linked list representation of stack */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};
// here we will assume enqueue as push, so dequeue will be costly here.
Node* top = NULL;

void enqueue(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = top;
	top = temp;
}

int dequeue(){
	Node* temp = top;
	int data;
	if(!top)
		return INT_MIN;
	if(!top->next){
		data = temp->data;
		delete temp;
		top = NULL;
		return data;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Node* temp2 = temp->next;
	temp->next = NULL;
	data = temp2->data;
	delete temp2;
	return data;
}

int main(){
	int d;
	enqueue(1);
	
	d = dequeue(); // d = 1
	(d == INT_MIN) ? cout<<"The stack is empty"<<endl :cout<<d<<" is popped"<<endl;
	d = dequeue(); // d = INT_MIN
	(d == INT_MIN) ? cout<<"The stack is empty"<<endl :cout<<d<<" is popped"<<endl;

	enqueue(1);
	enqueue(2);
	
	d = dequeue(); // d = 1
	d == INT_MIN ? cout<<"The stack is empty"<<endl :cout<<d<<" is popped"<<endl;

	enqueue(3); 
	enqueue(4);
	enqueue(5);
	enqueue(6);
	
	d = dequeue(); // d = 2
	(d == INT_MIN) ? cout<<"The stack is empty"<<endl :cout<<d<<" is popped"<<endl;

	return 0;	
}
