/* C++ program to add 2 numbers which are stored as linked lists..
for ex. 365 is stored as 5->6->3, 248 is stored as 8->4->2, addition output should be 3->1->6 which is 613*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

/* tail pointer is used for adding element in list at the end.
we can add element in list at the end without tail pointer but we have to 
traverse the list till the end everytime we add new element, as we would 
have only head pointer which points to the first element of the list..*/
 
Node* head1 = NULL;
Node* tail1 = NULL;
Node* head2 = NULL;
Node* tail2 = NULL;
Node* head3 = NULL;
Node* tail3 = NULL;

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

void add(Node* head1, Node* head2){
	Node* temp1 = head1;
	Node* temp2 = head2;
	int carry = 0, sum;
	while(temp1 && temp2){
		sum = temp1->data + temp2->data + carry;
		carry = sum/10;
		add_end(&head3, &tail3, sum%10);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	while(temp1){
		sum = temp1->data + carry;
		carry = sum/10;
		add_end(&head3, &tail3, sum%10);
		temp1 = temp1->next;
	}
	while(temp2){
		sum = temp2->data + carry;
		carry = sum/10;
		add_end(&head3, &tail3, sum%10);
		temp2 = temp2->next;
	}
	if(carry>0){
		add_end(&head3, &tail3, carry);
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

void make_list(Node** head, Node** tail, int data){
	int temp = data, num;
	while(temp>0){
		num = temp%10;
		add_end(head, tail, num);
		temp /= 10;
	}
}

int main(){
	int a, b, temp;
	cout<<"Enter the numbers to add"<<endl;
	cin>>a>>b;
	
	// making the desired linked list of number
	make_list(&head1, &tail1, a);
	make_list(&head2, &tail2, b);
	
	add(head1, head2);
	cout<<"The addition of 2 numbers a and b in reverse order is"<<endl;
	print_list(head3); //should print the number in reverse order
	return 0;
}

