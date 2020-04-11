/* C++ program to reverse a sub list of linked list.
We need to reverse the linked list from position m to n. For ex. if input is 
10->20->30->40->50->60->70->NULL and m = 3, n = 6, then the output should be
10->20->60->50->40->30->70->NULL. */

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
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

Node* reverse_M_to_N(Node* temp, int M, int N){
	Node* prev = NULL;
	Node* curr = temp;
	Node* fu = NULL;
	for(int i = 0; i<N-M+1; i++){
		if(curr){
			fu = curr->next;
			curr->next = prev;
			prev = curr;
			curr = fu;
		}
	}
	if(curr)
		temp->next = curr;
	return prev;
}

void reverse_sublist(int M, int N){
	int i;
	Node* temp = head;
	if(M == N){
		return;
	}
	if(M == 1){
		head = reverse_M_to_N(temp, M, N);
		return;
	}
	for(i=1; i<M-1; i++){
		temp = temp->next;
	}
	temp->next = reverse_M_to_N(temp->next, M, N);
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
	int M, N, num, num_elements,i;
	cout<<"Enter the number of elements:"<<endl;
	cin>>num_elements;
	for(i=0; i<num_elements; i++){
		cin>>num;
		add_end(num);
	}
	
	cout<<"Enter M and N"<<endl;
	cin>>M>>N;
	
	reverse_sublist(M, N);
	print_list();
	return 0;
}

