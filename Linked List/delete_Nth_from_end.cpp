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

Node* del_Nth_from_end(Node* head, int N){
	Node* temp;
	Node* temp2;
	if(N == count){
		temp = head;
		head = head->next;
		delete temp;
		count--;
		return head;
	}
	temp = head;
	for(int i = 0; i<count-N-1; i++){
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = temp2->next;
	delete temp2;
	count--;
	return head;
}

void print_list(Node* head){
	Node* temp = head;
	cout<<"The elements of the list are:"<<endl;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(){
	
	Node* head = NULL;
	head = add_end(head, 5);
	head = add_end(head, 2);
	head = add_end(head, 1);
	head = add_end(head, 8);
	head = add_end(head, 9);
	head = del_Nth_from_end(head, 2);
	print_list(head); // list will be 5 2 1 9
	
	head = add_end(head, 6);
	head = add_end(head, 7);
	head = del_Nth_from_end(head, count);
	print_list(head); // list will be 2 1 9 6 7
	
	head = del_Nth_from_end(head, 1);
	print_list(head); // list will be 2 1 9 6
	
	return 0;	
}







