/* 
C++ program to split the linked list alternatively.
Ex. if given input array is 1 2 3 4 5 6 7 then the output should be
1 3 5 7 and 2 4 6
*/
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

void add_end(Node** head, Node** tail, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
		*tail = temp;
		return;
	}
	(*tail)->next = temp;
	*tail = temp;
}

void print_list(Node* head){
	Node* temp = head;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void alternative_split(Node** head1, Node** head2){
	Node* temp1 = *head1;
	Node* temp2 = *head2;
	while(temp1!= NULL && temp2!= NULL){
		temp1->next = temp2->next;
		temp1 = temp1->next;
		if(temp1){
			temp2->next = temp1->next;
			temp2 = temp2->next; 
		}
		else{
			break;
		}
	}
}

int main(){
	Node* head = NULL;
	Node* tail = NULL;
	Node* head1 = NULL;
	Node* head2 = NULL;
	add_end(&head, &tail, 1);
	add_end(&head, &tail, 2);
	add_end(&head, &tail, 3);
	add_end(&head, &tail, 4);
	add_end(&head, &tail, 5);
	add_end(&head, &tail, 6);
	add_end(&head, &tail, 7);
	add_end(&head, &tail, 8);
	
	head1 = head;
	head2 = head->next;
	alternative_split(&head1, &head2);
	
	cout<<"The linked lists after alternative splitting are "<<endl;
	print_list(head1);
	print_list(head2);
	
	return 0;
}

