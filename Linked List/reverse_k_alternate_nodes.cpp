/* C++ program to reverse alternate k nodes in a singly linked list..
for ex. if list is 1->2->3->4->5->6->7->8->9->NULL, and k is 3, then
the output should be 3->2->1->4->5->6->9->8->7->NULL */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL; // points to last element, makes adding node at end easier

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

Node* reverse_k(Node* temp, Node* start, int k){
	int i;
	Node* prev = NULL;
	Node* fu = NULL;
	Node* curr = temp;
	for(i=1;i<=k;i++){
		if(curr){
			fu = curr->next;
			curr->next = prev;
			prev = curr;
			curr = fu;
		}
	}
	if(start){
		start->next = prev;
	}
	if(curr){
		temp->next = curr;
	}
	if(temp == head){
		head = prev;
	}
	for(i=0;i<k-1;i++){
		if(curr){
			curr = curr->next;
		}
	}
	return curr;
}

void reverse_alternate_knodes(int k){
	Node* curr = head;
	Node* start = NULL;
	while(curr){
		curr = reverse_k(curr, start, k);
		start = curr;
		if(curr)
			curr = curr->next;
	}
}

void print_list(){
	Node* temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int N, k, i, t;
	cout<<"Enter the number of elements and k:\n";
	cin>>N>>k;
	cout<<"Enter N elements\n";
	for(i=0;i<N;i++){
		cin>>t;
		add_end(t);
	}
	reverse_alternate_knodes(k);
	print_list();
	
	return 0;
}

