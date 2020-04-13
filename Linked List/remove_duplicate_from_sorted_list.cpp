/* C++ program to remove duplicates from sorted linked list.
delete all nodes that have duplicate numbers(all occurences), leaving only
numbers that appear once in the original list For ex, if the input list is
 23->28->28->35->49->49->53->53 then the output should be 23->35 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head;
Node* tail;

void add_end(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void remove_duplicate(){
	Node* temp = head;
	Node* temp2 = head;
	int data;
	int flag;
	while(temp){
		if(temp->next)
			data = temp->next->data;
		flag = 0;
		while(temp && temp->data == data){
			flag = 1;
			if(temp == head){
				head = head->next;
				temp->next = NULL;
				delete temp;
				temp = head;
				temp2 = head;
			}else{
				temp2->next = temp->next;
				temp->next = NULL;
				delete temp;
				temp = temp2->next;
			}
		}
		
		// if there has been not a single deletion in this loop, we will 
		//execute the command below, by just moving our temp pointer forward
		//and storing previous(temp2) pointer.
		if(temp && flag == 0){
			temp2 = temp;
			temp = temp->next;
		}
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
	int N, num, i;
	cout<<"Enter the number of elements"<<endl;
	cin>>N;
	cout<<"Enter the elements of the list"<<endl;
	for(i=0;i<N;i++){
		cin>>num;
		add_end(num);
	}
	
	remove_duplicate();
	if(!head){
		cout<<"There are no unique elements in the list"<<endl;
	}else{
		cout<<"After removing duplicates, the list is "<<endl;
		print_list();
	}
	return 0;
}

