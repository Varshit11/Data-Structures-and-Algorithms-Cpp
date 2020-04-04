#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
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

void find_length_iterative(Node* head){
	Node* temp = head;
	int count = 0;
	while(temp!=NULL){
		count++;
		temp = temp->next;
	}
	cout<<"The length of the list using iterative method is "<<count<<endl;
}

int find_length_recursion(Node* head){
	if(head == NULL){
		return 0;
	}
	return (1+find_length_recursion(head->next));
}

int main(){
	Node* head = NULL;
	head = add_begin(head, 1);
	head = add_end(head, 2);
	head = add_end(head, 3);
	head = add_end(head, 4);
	head = add_end(head, 5);
	find_length_iterative(head);
	int length = find_length_recursion(head);
	cout<<"The length of the list using recursion is "<<length<<endl;
	head = add_end(head, 6);
	head = add_end(head, 7);
	length = find_length_recursion(head);
	cout<<"The length of the list using recursion is "<<length<<endl;
	return 0;
}



