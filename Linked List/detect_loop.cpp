#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void detect_loop(){
	Node* slow_ptr = head;
	Node* fast_ptr = head;
	while(slow_ptr!= NULL && fast_ptr!=NULL && fast_ptr->next!=NULL){
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if(slow_ptr == fast_ptr){
			cout<<"There is loop in the list"<<endl;
			cout<<"The value where there is loop is "<<fast_ptr->next->data<<endl;
			break;
		}
	}
	if(slow_ptr == NULL || fast_ptr ==NULL|| fast_ptr->next == NULL){
		cout<<"There is no loop in the list"<<endl;
	}
}

int main(){
	add_end(1);
	add_end(2);
	add_end(4);
	add_end(5);
	add_end(6);
	tail->next = head->next; // making loop;
	detect_loop();
	return 0;
}


