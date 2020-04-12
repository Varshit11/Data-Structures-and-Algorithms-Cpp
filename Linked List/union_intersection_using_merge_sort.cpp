/* C++ program to find union and intersection of 2 linked list
Assumption - A particular linked list has unique values.
Implement this using sorting */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1;
Node* head2;
Node* head_union;
Node* head_intersection;
Node* tail_union; // for easier adding of elements at the end..optional to use
Node* tail_intersection; // for easier adding of elements at the end..optional to use

void add_beg(Node** head, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

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

int count(Node* head){
	int c = 0;
	Node* temp = head;
	while(temp!=NULL){
		c++;
		temp = temp->next;
	}
	return c;
}

Node* merge(Node* first, Node* second){
	Node* final;
	Node* temp3;
	Node* temp1 = first;
	Node* temp2 = second;
	if(temp1->data<= temp2->data){
		final = temp1;
		temp1 = temp1->next;
	}else{
		final = temp2;
		temp2 = temp2->next;
	}
	temp3 = final;
	while(temp1 && temp2){
		if(temp1->data<= temp2->data){
			temp3->next = temp1;
			temp1 = temp1->next;
		}else{
			temp3->next = temp2;
			temp2 = temp2->next;
		}
		temp3 = temp3->next;
	}
	temp3->next = temp1 ? temp1 : temp2;
	return final;
}

Node* merge_sort(Node* head){
	int mid = count(head)/2;
	if(mid > 0){
		Node* middle = head;
		for(int i = 0; i<mid-1; i++){
			middle = middle->next;
		}
		Node* second = middle->next;
		middle->next = NULL;
		head = merge_sort(head);
		second = merge_sort(second);
		Node* merged = merge(head, second);
		return merged;
	}else{
		return head;
	}
}

void union_intersection(){
	Node* temp1 = head1;
	Node* temp2 = head2;
	while(temp1 && temp2){
		if(temp1->data < temp2->data){
			add_end(&head_union, &tail_union, temp1->data);
			temp1 = temp1->next;
		}else if(temp2->data < temp1->data){
			add_end(&head_union, &tail_union, temp2->data);
			temp2 = temp2->next;
		}else{
			add_end(&head_intersection, &tail_intersection, temp1->data);
			add_end(&head_union, &tail_union, temp1->data);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	tail_union->next = temp1 ? temp1 : temp2;
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
	cout<<"Enter the number of elements in 2 lists"<<endl;
	cin>>n1>>n2;
	cout<<"Enter the elements of list1"<<endl;
	for(i=0;i<n1;i++){
		cin>>num;
		add_beg(&head1, num);
	}
	cout<<"Enter the elements of list2"<<endl;
	for(i=0;i<n2;i++){
		cin>>num;
		add_beg(&head2, num);
	}
	head1 = merge_sort(head1);
	head2 = merge_sort(head2);
	union_intersection();
	
	cout<<"The union of list1 and list2 is"<<endl;
	print_list(head_union);
	cout<<"The intersection of list1 and list2 is"<<endl;
	print_list(head_intersection);
	
	return 0;
}

