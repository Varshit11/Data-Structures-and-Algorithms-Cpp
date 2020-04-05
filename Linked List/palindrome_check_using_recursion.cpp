// C++ program to check a list is palindrome or not.
// Implement using recursion.

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

bool palindrome_recursion(Node** temp1, Node* temp2){
	if(temp2 == NULL){
		return true;
	}
	bool j = palindrome_recursion(temp1, temp2->next);
	if(j){
		bool k = (*temp1)->c == temp2->c;
		*temp1 = (*temp1)->next;
		return k;
	}else{
		return j;
	}
}

int main(){
	add_end('a');
	add_end('b');
	add_end('c');
	add_end('c');
	add_end('b');
	add_end('a');
	if(palindrome_recursion(&head, head)){
		cout<<"The linked list is palindrome"<<endl;
	}else{
		cout<<"The linked list is not palindrome"<<endl;
	}
	return 0;
}

