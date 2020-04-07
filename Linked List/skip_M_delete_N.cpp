/* C++ program to delete N nodes after skipping M nodes*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(!head){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

/* if M = 0, i.e there is no skipping before deleting then we would delete the 
entire list*/
void delete_whole_list(){
	Node* temp;
	while(head){
		temp = head;
		head = head->next;
		delete temp;
	}
}

Node* delete_N(Node* temp, int N){
	int i;
	Node* temp2 = temp->next;
	Node* temp3;
	temp->next = NULL;
	for(i=0;i<N;i++){
		if(!temp2){
			break;
		}
		temp3 = temp2;
		temp2 = temp2->next;
		delete temp3;
	}
	return temp2;
}


/* if M > 1, then we will skip M nodes and delete N nodes*/
void delete_N_skip_M(int M, int N){
	Node* temp = head;
	int i,j;
	while(temp){
		for(i=0; i< M-1; i++){
			temp = temp->next; // skipping nodes
		}
		temp->next = delete_N(temp, N);
		temp = temp->next;
	}
}

void print_list(){
	Node* temp = head;
	while(temp!= NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int M, N, num, i, d;
	cout<<"Enter the number of elements in the linked list"<<endl;
	cin>>num;
	cout<<"Enter the elements of the linked list"<<endl;
	for(i=0;i<num;i++){
		cin>>d;
		add_end(d);
	}
	cout<<"Enter M(skip nodes) and N(delete nodes)"<<endl;
	cin>>M>>N;
	if(M == 0){
		cout<<"Since M = 0 so deleting entire list"<<endl;
		delete_whole_list();
		exit(0);
	}else if(N == 0){
		cout<<"Since N = 0 so there is no deletion.";
		cout<<" The list is"<<endl;
		print_list();
		exit(0);
	}else{
		delete_N_skip_M(M, N);
		cout<<"The list after skipping "<<M<<" nodes and deleting "<<N<<" nodes is\n";
		print_list();
	}
	return 0;
}

