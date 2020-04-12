/* C++ program to find next greater element in a linked list
 If no larger element present on the right side then return 0, for ex. 
 if input is 2->7->4->3->5, then output should be 7->0->5->5->0
 We will implement this without using any extra space. We used recursion to solve
 the same problem which takes extra space, Hint - reverse the linked list */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1;
Node* tail1;
Node* ans_head;
int MAX;

void add_end(Node** head, Node** tail, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(!(*head)){
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

void reverse(){
	Node* curr = head1;
	Node* prev = NULL;
	Node* fu = NULL;
	while(curr){
		fu = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fu;
	}
	head1 = prev;
}

void find_next_greater(){
	reverse();
	Node* temp = head1;
	MAX = temp->data;
	while(temp){
		if(temp->data >= MAX){
			add_beg(&ans_head, 0);
			MAX = temp->data;
		}else{
			add_beg(&ans_head, MAX);
		}
		temp = temp->next;
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
	int N, num, i;
	cout<<"Enter the number of elements in the list"<<endl;
	cin>>N;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(&head1, &tail1, num);
	}
	
	find_next_greater();
	cout<<"The next greater element list is"<<endl;
	print_list(ans_head);
}

