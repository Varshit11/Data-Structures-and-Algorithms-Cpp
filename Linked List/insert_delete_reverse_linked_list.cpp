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

Node* add_after(Node* head, int data1, int data2){
	// we have to insert node with value data2 after the node with value data1..
	Node* temp = create_node(data2);
	if(head == NULL){
		head = temp;
		return head;
	}
	Node* temp2 = head;
	while(temp2->data!= data1 && temp2!= NULL){
		temp2 = temp2->next;
	}
	if(temp2!= NULL){
		temp->next = temp2->next;
		temp2->next = temp;
		return head;
	}else{
		cout<<"Insertion failed as there is no node with value "<<data1<<endl;
		return head;
	}
}

Node* delete_node(Node* head, int data){
	if(head == NULL){
		cout<<"Cannot delete anything, the linked list is empty"<<endl;
		return head;
	}
	Node* temp = head;
	// if node is at beginning
	if(head->data == data){
		head = head->next;
		delete temp;
		return head;
	}
	
	// if any other node
	while(temp->next!=NULL && temp->next->data !=data){
		temp = temp->next;
	}
	if(temp->next != NULL){
		Node* temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
		return head;
	}else{
		cout<<"Deletion failed as there is no data in the linked list with value "<<data<<endl;
		return head;
	}
}

Node* reverse_list(Node* head){
	Node* cur = head;
	Node* prev = NULL;
	Node* fu = NULL;
	while(cur!=NULL){
		fu = cur->next;
		cur->next = prev;
		prev = cur;
		cur = fu;
	}
	head = prev;
	return head;
}

void print_list(Node* head){
	Node* temp = head;
	cout<<"The list elements are"<<endl;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	Node* head = NULL;
	head = add_begin(head, 1);
	head = add_end(head, 2);
	head = add_after(head, 2, 4);
	print_list(head); // should print 1 2 4
	
	head = add_after(head, 2, 3);
	head = add_end(head, 5);
	print_list(head); // should print 1 2 3 4 5
	
	head = add_end(head, 6);
	head = add_end(head, 7);
	print_list(head); // should print 1 2 3 4 5 6 7
	
	head = delete_node(head, 6);
	head = delete_node(head, 7);
	print_list(head); // should print 1 2 3 4 5
	
	head = delete_node(head, 1);
	head = delete_node(head, 9); // no such element should print no node with value 9
	head = reverse_list(head);
	print_list(head); // should print 5 4 3 2
	
	return 0;
	
	
}
