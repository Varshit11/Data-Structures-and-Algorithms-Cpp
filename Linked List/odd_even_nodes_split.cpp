/* C++ program  to group all odd nodes followed by even nodes. We are 
talking about node number not the values in node. Do this in space 
complexity O(1) and time complexity O(n). For ex. if input is 1->2->3->4->5
then output should be 1->3->5->2->4 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1;
Node* tail1;
Node* head2;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(head1 == NULL){
		head1 = temp;
		tail1 = temp;
		return;
	}
	tail1->next = temp;
	tail1 = temp;
}

void odd_even_split(int N){
	Node* temp = head1;
	head2 = head1->next;
	Node* temp2 = head2;
	while(temp && temp2){
		temp->next = temp2->next;
		if(N%2 == 0){
			tail1 = temp;
		}
		temp = temp->next;
		if(temp){
			temp2->next = temp->next;
			temp2 = temp2->next;
		}
	}
	tail1->next = head2;
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
	int N, num, i;
	cout<<"Enter the number of elements in the list"<<endl;
	cin>>N;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(num);
	}
	
	odd_even_split(N);
	cout<<"After  odd even splitting of nodes, the final list is"<<endl;
	print_list(head1);
	return 0;
}

