/* C++ program to find next greater element in a linked list
 If no larger element present on the right side then return 0, for ex. 
 if input is 2->7->4->3->5, then output should be 7->0->5->5->0*/
 
#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

int MAX;
Node* head1;
Node* tail1;
Node* ans_head;

void add_end(Node** head, Node** tail, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
		*tail = temp;
		return;
	}
	(*tail)->next = temp;
	*tail = temp;
}

void add_beg(Node** head, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

int find_next_greater(Node* temp){
	if(temp->next == NULL){
		MAX = temp->data;
		add_beg(&ans_head, 0);
		return MAX;
	}
	int j = find_next_greater(temp->next);
	if(temp->data>= j){
		add_beg(&ans_head, 0);
		MAX = temp->data;
	}else{
		add_beg(&ans_head, j);
		MAX = j;
	}
	return MAX;
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
	cout<<"Enter the number of elements in the list"<<endl;
	cin>>N;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(&head1, &tail1, num);
	}
	
	int j = find_next_greater(head1);
	cout<<"The next greater element list is"<<endl;
	print_list(ans_head);
	
	return 0;
}
