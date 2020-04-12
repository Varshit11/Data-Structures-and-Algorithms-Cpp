/* C++ program to rotate the list to the right by k places, k>0
for ex. if input is 10->20->30->40->50 and k = 2
the output should be 40->50->10->20->30 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1;
Node* tail1;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(!head1){
		head1 = temp;
		tail1 = temp;
		return;
	}
	tail1->next = temp;
	tail1 = temp;
}

void rotate_right(int N, int k){
	Node* temp = head1;
	tail1->next = head1;
	for(int i=0; i<N-k-1; i++){
		temp = temp->next;
	}
	head1 = temp->next;
	temp->next = NULL;
}

void print_list(){
	Node* temp = head1;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int main(){
	int N, num, i, k;
	cout<<"Enter the number of elements in the linked list and k"<<endl;
	cin>>N>>k;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(num);
	}
	
	rotate_right(N, k);
	cout<<"After rotating the list k elements to the right, the new list is"<<endl;
	print_list();
	return 0;
}

