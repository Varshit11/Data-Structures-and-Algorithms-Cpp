//C++ code to check a given linked list of characters in palindrome or not

#include<iostream>
using namespace std;

class Node{
	public:
		char c;
		Node* next;
};
int count = 0;
Node* head = NULL;
Node* tail = NULL;

void add_end(char c){
	Node* temp = new Node;
	temp->c = c;
	temp->next = NULL;
	count++;
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void print_list(Node* h){
	Node* temp = h;
	cout<<"The contents of the list are "<<endl;
	while(temp!= NULL){
		cout<<temp->c<<" ";
		temp = temp->next;
	}
	cout<<"\n";
}

Node* reverse(Node* mid){
	Node* cur = mid;
	Node* prev = NULL;
	Node* fu = NULL;
	while(cur!= NULL){
		fu = cur->next;
		cur->next = prev;
		prev = cur;
		cur = fu;
	}
	return prev;
}

void check_palindrome(){
	print_list(head);
	Node* temp = head;
	Node* mid = head;
	Node* head2;
	Node* temp2;
	int mid_index = count/2, i, flag = 0;
	
	if(count%2 == 0){
		mid_index -= 1;
	}
	for(i = 0; i<mid_index; i++){
		mid = mid->next;
	}
	head2 = reverse(mid->next);	
	temp2 = head2;
	for(i = 1; i<=mid_index; i++){
		if(temp->c - temp2->c != 0){
			flag = 1;
			break;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	if(flag == 1){
		cout<<"The given linked list is not palindrome"<<endl;
	}else{
		cout<<"The given linked list is a palindrome"<<endl;
	}
	
	mid->next = reverse(head2);  // to make original list again.
	
	/*just to check if we have joined the list correctly after breaking in two.
	you can uncomment the below line..it is just for verifying the list
	cout<<"After joining the linked list becomes"<<endl;
	print_list(head);*/
}

int main(){
	add_end('a');
	add_end('b');
	add_end('c');
	add_end('c');
	add_end('b');
	add_end('a');
	check_palindrome();
	return 0;
}


