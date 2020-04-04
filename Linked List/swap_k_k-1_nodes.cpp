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

Node* swap_nodes(Node* head, int k){
	Node* temp1;
	Node* temp2;
	if(k == 1){
		cout<<"Can't swap K should be greater than 1"<<endl;
		return head;
	}else if(k == count){
		temp1 = head;
		head = head->next;
		temp1->next = head->next;
		head->next = temp1;
		return head;
	}else{
		temp1 = head;
		for(int i = 0;i<count-k-1; i++){
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = temp2->next;
		temp2->next = temp1->next->next;
		temp1->next->next = temp2;
		return head;
	}
}

void print_list(Node* head){
	Node* temp = head;
	cout<<"The elements of the list are:\n";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

int main(){
	Node* head = NULL;
	head = add_end(head, 10);
	head = add_end(head, 3);
	head = add_end(head, 1);
	head = add_end(head, 9);
	print_list(head); // list will be 10 3 1 9
	
	head = swap_nodes(head, 3);
	print_list(head); // list will be 10 1 3 9
	
	head = swap_nodes(head, 3); // again list will be 10 3 1 9
	head = swap_nodes(head, 4);
	print_list(head); // list will be 3 10 1 9
	
	head = swap_nodes(head, 1); // nothing will happen as k is 1
	head = swap_nodes(head, 2);
	print_list(head); // list will be 3 10 9 1
	
	return 0;
}




