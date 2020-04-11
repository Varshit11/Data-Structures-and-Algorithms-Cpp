/* C++ program to merge sort a linked list without using any extra space*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;
Node* head3 = NULL; // stores the final answer..

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

int count(Node* head1){
	int c = 0;
	Node* temp = head1;
	while(temp != NULL){
		c++;
		temp = temp->next;
	}
	return c;
}

Node* merge(Node* head1, Node* head2){
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* final;
	Node* temp3;
	if(temp1->data <= temp2->data){
		final = temp1;
		temp1 = temp1->next;
	}else{
		final = temp2;
		temp2 = temp2->next;
	}
	temp3 = final;
	while(temp1 && temp2){
		if(temp1->data <= temp2->data){
			temp3->next = temp1;
			temp1 = temp1->next;
		}else{
			temp3->next = temp2;
			temp2 = temp2->next;
		}
		temp3 = temp3->next;
	}
	while(temp1){
		temp3->next = temp1;
		temp1 = temp1->next;
		temp3 = temp3->next;
	}
	while(temp2){
		temp3->next = temp2;
		temp2 = temp2->next;
		temp3 = temp3->next;
	}
	return final;
}

Node* mergesort(Node* head_temp){
	int center = count(head_temp)/2;
	if(center>0){
		Node* middle = head_temp;
		for(int i = 0; i<center-1; i++){
			middle = middle->next;
		}
		Node* head2 = middle->next;
		middle->next = NULL;
		head_temp = mergesort(head_temp);
		head2 = mergesort(head2);
		head3 = merge(head_temp, head2);
		return head3;
	}else{
		return head_temp;
	}
}

void print_list(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int N, i, num;
	cout<<"Enter the number of elements in the linked list"<<endl;
	cin>>N;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(num);
	}
	head3 = mergesort(head);
	cout<<"After merge sort the final list is"<<endl;
	print_list(head3);
	return 0;
}
