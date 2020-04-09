/* given a doubly linked list, one which points to the next
element and other points randomly to some other node, we have to
clone the original list */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* rand;
};

Node* head = NULL;
Node* tail = NULL;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	temp->rand = NULL;
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

Node* add_between(Node* temp){
	Node* temp2 = new Node;
	temp2->data = temp->data;
	temp2->next = temp->next;
	temp2->rand = NULL;
	return temp2;
}


Node* clone_list(){
	Node* temp = head;
	Node* temp2;
	while(temp){
		temp->next = add_between(temp);
		temp = temp->next->next;
	}
	temp = head;
	while(temp){
		temp->next->rand = temp->rand->next;
		temp = temp->next->next;
	}
	temp = head;
	temp2 = head->next;
	Node* final = temp2;
	while(temp && temp2){
		temp->next = temp2->next;
		temp = temp->next;
		if(temp){
			temp2->next = temp->next;
			temp2 = temp2->next;
		}
	}
	return final;
}

void print_list(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

void print_rand(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->rand->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	add_end(1);
	add_end(2);
	add_end(3);
	add_end(4);
	add_end(5);
	// making the random pointer point to any element
	head->rand = head->next->next; // 1 rand points to 3
	head->next->rand = head->next->next->next; // 2 rand points to 4
	head->next->next->rand = head; // 3 rand points to 1
	head->next->next->next->rand = head->next; // 4 rand points to 2
	tail->rand = head; // 5 rand points to 1
	
	Node* final = clone_list();
	cout<<"The cloned list is"<<endl;
	print_list(final); // should print 1 2 3 4 5
	cout<<"The random pointers of list are"<<endl;
	print_rand(final); // should print 3 4 1 2 1
	return 0;
	
}

