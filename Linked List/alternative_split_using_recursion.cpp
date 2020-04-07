/* C++ program to do alternative splitting of the linked list using recursion*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;
Node* head1 = NULL;
Node* head2 = NULL;

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

int alternate_split(Node* temp){
	if(!temp){
		return 0;
	}
	int j = 1+ alternate_split(temp->next);
	if(j%2 == 0){
		temp->next = head1;
		head1 = temp;
	}else{
		temp->next = head2;
		head2 = temp;
	}
	return j;
}

void print_list(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int N, i, d;
	cout<<"Enter the number of elements in the list"<<endl;
	cin>>N;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<N;i++){
		cin>>d;
		add_end(d);
	}
	int j = alternate_split(head);
	cout<<"The lists after splitting the original linked list are"<<endl;
	if(N%2 == 0){
		print_list(head1);
		print_list(head2);
	}else{
		print_list(head2);
		print_list(head1);
	}
	return 0;
}


