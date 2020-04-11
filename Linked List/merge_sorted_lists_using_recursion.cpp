/* C++ program to merge 2 sorted linked list into 1 sorted list.
We have to implement this using recursion. For ex. if list1 = 1->5->6->9->NULL
and list2 = 3->4->7->NULL, the final list will be, 1->3->4->5->6->7->9->NULL */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* tail1 = NULL;
Node* tail2 = NULL;
Node* head3 = NULL;
Node* temp3 = NULL;

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

void merge(Node* temp1, Node* temp2){
	if(!temp1 && !temp2){
		return;
	}
	else if(temp1 && !temp2){
		temp3->next = temp1;
		temp3 = temp3->next;
		merge(temp1->next, temp2);
	}
	else if(!temp1 && temp2){
		temp3->next = temp2;
		temp3 = temp3->next;
		merge(temp1, temp2->next);
	}
	else{
		if(temp1->data <= temp2->data){
			temp3->next = temp1;
			temp3 = temp3->next;
			merge(temp1->next, temp2);
		}else{
			temp3->next = temp2;
			temp3 = temp3->next;
			merge(temp1, temp2->next);
		}
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
	int n1, n2, num, i;
	cout<<"Enter the length of 2 lists"<<endl;
	cin>>n1>>n2;
	cout<<"Enter the elements of list1 (in sorted order)"<<endl;
	for(i=0;i<n1;i++){
		cin>>num;
		add_end(&head1, &tail1, num);
	}
 	cout<<"Enter the elements of list2 (in sorted order)"<<endl;
 	for(i=0;i<n2; i++){
 		cin>>num;
 		add_end(&head2, &tail2, num);
	}
	if(head1->data <= head2->data){
		head3 = head1;
		head1 = head1->next;
	}else{
		head3 = head2;
		head2 = head2->next;
	}
	temp3 = head3;
	
	merge(head1, head2);
	cout<<"After merging 2 sorted lists into one, the final sorted list is"<<endl;
	print_list(head3);
	return 0;
}

