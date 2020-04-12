/* C++ program to swap every 2 adjacent nodes, in a linked list..
For ex. if list is 1-2->3->4 then the output should be 2-1->4->3,
adjust the pointers, dont swap the data of linked lists */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head;
Node* tail; // for easier adding of elements at end of linked list, optional to use

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

void swap_adjacent_nodes(){
	Node* temp1 = head;
	Node* temp2;
	Node* temp3 = temp1;
	while(temp1){
		temp2 = temp1->next;
		if(!temp2){
			break;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
		if(temp1 == head){
			head = temp2;
		}
		if(temp2 != head){
			temp3->next = temp2;
		}
		temp3 = temp1;
		temp1 = temp1->next;
	}
}

void print_list(){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int N, num, i;
	cout<<"Enter the number of elements"<<endl;
	cin>>N;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(num);
	}
	
	swap_adjacent_nodes();
	print_list();
	
	return 0;
}

