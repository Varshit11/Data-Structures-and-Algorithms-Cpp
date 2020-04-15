/* C++ program Design and Implement Special Stack Data Structure. 
push(), pop(), getMinimum(), findMiddleElement(), deleteMiddleElement(). 
All these operations should be in O(1) time.*/

/* solution - We see that we cannot implement a stack like this using arrays, 
singly linked list. You can cross check it. We can implement this stack using
doubly linked list*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
};

Node* middle = NULL; // for accessing middle in O(1) time.
Node* head = NULL; // same as top of stack..
int count = 0; // for changing the middle pointer according to count..

void push(int data){
	Node* temp = new Node;
	count++;
	temp->data = data;
	temp->next = head;
	temp->prev = NULL;
	if(!head){
		head = temp;
		middle = temp;
		return;
	}
	head->prev = temp;
	head = temp;
	if(count%2 == 0){
		middle = middle->prev;
	}
}

void pop(){
	if(!head){
		return;
	}
	Node* temp = head;
	head = head->next;
	if(head)
		head->prev = NULL;
	temp->next = NULL;
	delete temp;
	count--;
	if(count == 1){
		middle = head;
		return;
	}
	if(count%2 == 1)
		middle = middle->next;
}

int top(){
	if(!head)
		return -1;
	return head->data;
}

int find_middle_element(){
	if(!head)
		return -1;
	return middle->data;
}

void delete_middle_element(){
	if(middle == head){
		pop();
		return;
	}
	Node* temp = middle;
	if(count%2 == 1){
		middle = middle->prev;
	}else{
		middle = middle->next;
	}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	delete temp;
	count--;
}

int main(){
	push(1);
	push(2);
	
	cout<<find_middle_element()<<endl; // should display 2
	delete_middle_element();
	cout<<find_middle_element()<<endl; // should display 1
	
	push(3);
	push(4);
	push(5);
	
	cout<<find_middle_element()<<endl; // should display 4
	delete_middle_element();
	cout<<find_middle_element()<<endl; // should display 3
	delete_middle_element();
	cout<<find_middle_element()<<endl; // should display 5
	delete_middle_element();
	cout<<find_middle_element()<<endl; // should display 1
	
	return 0;
}
 
