/* C++ program to split the circular linked list in 2 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1 = NULL;
Node* tail = NULL;
Node* head2 = NULL;
int count = 0;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	count++;
	if(head1 == NULL){
		head1 = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void split(){
	int mid = count/2, i;
	if(count%2 == 0){
		mid--;
	}
	Node* temp = head1;
	for(i=0;i<mid; i++){
		temp = temp->next;
	}
	head2 = temp->next;
	temp->next = head1;
	tail->next = head2;
}

void print_list(Node* head){
	Node* temp = head;
	while(temp->next != head){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

int main(){
	add_end(1);
	add_end(2);
	add_end(3);
	add_end(4);
	add_end(5);
	tail->next = head1;
	split();
	cout<<"The 2 splitted circular linked lists are"<<endl;
	print_list(head1);
	print_list(head2);
	return 0;
}
