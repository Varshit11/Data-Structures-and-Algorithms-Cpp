#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

int count = 0;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	count++;
	return temp;
}

Node* add_begin(Node* head, int data){
	Node* temp = create_node(data);
	if(head == NULL){
		head = temp;
		return head;
	}
	temp->next = head;
	head = temp;
	return head;
}

Node* add_end(Node* head, int data){
	Node* temp = create_node(data);
	if(head==NULL){
		head = temp;
		return head;
	}
	Node* temp2 = head;
	while(temp2->next != NULL){
		temp2 = temp2->next;
	}
	temp2->next = temp;
	return head;
}

int find_kth_from_end(Node* head, int k){
	Node* temp = head;
	for(int i =0; i<count-k; i++){
		temp = temp->next;
	}
	return temp->data;
}

int main(){
	Node* head = NULL;
	head = add_end(head, 1);
	head = add_end(head, 2);
	head = add_end(head, 3);
	head = add_end(head, 4);
	head = add_end(head, 5);
	int pos = 2;
	int element = find_kth_from_end(head, pos);
	cout<<"The "<<pos<<"th element from the end is "<<element<<endl;
	Node* temp = head;
	Node* temp2;
	while(temp!=NULL){
		temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
	head = NULL;
	count = 0;
	head = add_end(head, 9);
	head = add_end(head, 1);
	head = add_end(head, 8);
	pos = 1;
	element = find_kth_from_end(head, pos);
	cout<<"The "<<pos<<"th element from the end is "<<element<<endl;
	return 0;
	
}












