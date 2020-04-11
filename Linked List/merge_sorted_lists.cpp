/* C++ program to merge 2 sorted list into 1 list which is in increasing order.
The new list should be made by splicing together the nodes of the first two lists
For ex. If list1 = 1->5->6->9->NULL and list2 = 3->4->7->NULL, 
the resultant list should be, i.e Output = 1->3->4->5->6->7->9->NULL */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* tail1 = NULL; // points to last element, helps in easier adding elements at end.
Node* tail2 = NULL; // points to last element, helps in easier adding elements at end.
Node* head3 = NULL; // this is the head of the output list

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

// no need to take head1, head2 as arguments as they are declared global
void merge_lists(){
	Node* temp1 = head1;
	Node* temp2 = head2;
	Node* temp3;
	if(temp1->data <= temp2->data){
		head3 = temp1;
		temp1 = temp1->next;
	}else{
		head3 = temp2;
		temp2 = temp2->next;
	}
	temp3 = head3;
	while(temp1 && temp2){
		if(temp1->data <= temp2->data){
			temp3->next = temp1;
			temp1 = temp1->next;
		}else{
			temp3->next = temp2;
			temp2 = temp2->next;
		}
		temp3 = temp3->next;
	}
	while(temp1){
		temp3->next = temp1;
		temp1 = temp1->next;
		temp3 = temp3->next;
	}
	while(temp2){
		temp3->next = temp2;
		temp2 = temp2->next;
		temp3 = temp3->next;
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
	cout<<"Enter the number of elements in list1 and list2"<<endl;
	cin>>n1>>n2;
	cout<<"Enter the elements of list1 (in sorted order)"<<endl;
	for(i=0;i<n1;i++){
		cin>>num;
		add_end(&head1, &tail1, num);
	}
	cout<<"Enter the elements of list2 (in sorted order)"<<endl;
	for(i=0; i<n2; i++){
		cin>>num;
		add_end(&head2, &tail2, num);
	}
	// merging lists
	merge_lists();
	
	cout<<"After merging 2 sorted lists, the final list is"<<endl;
	print_list(head3);
	return 0;
}

