/* Write a C++ program, Given a linked list, reverse the nodes of a linked list k 
at a time and return its modified list, For ex. if list is 10->20->30->40->50, 
if k = 2, then output should be 20->10->40->30->50, 
if k = 3, the output should be 30->20->10->40->50 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int count = 0;
Node* temp2;
void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	count++;
	if(!head){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

Node* reverse(Node* temp, int k){
	Node* curr = temp;
	Node* prev = NULL;
	Node* fu = NULL;
	for(int i = 0; i<k; i++){
		fu = curr->next;
		curr->next = prev;
		prev = curr;
		curr = fu;
	}
	if(temp2!=head){
		temp2->next = prev;
	}
	if(temp == head){
		head = prev;
	}
	temp->next = curr;
	temp2 = temp;
	return temp;
}

void reverse_k(int k){
	if(k == 1){
		cout<<"Can't swap one node"<<endl;
		return;
	}
	Node* temp = head;
	temp2 = head;
	int it = count/k;
	while(it-- > 0){
		temp = reverse(temp, k);
		temp = temp->next;
	}
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
	int n1, num, i, k;
	cout<<"Enter the number of elements"<<endl;
	cin>>n1;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n1;i++){
		cin>>num;
		add_end(num);
	}
	cout<<"Enter the value of k"<<endl;
	cin>>k;
	
	reverse_k(k);
	cout<<"After swapping k nodes at a time, the final list is"<<endl;
	print_list();
	
	return 0;
}

