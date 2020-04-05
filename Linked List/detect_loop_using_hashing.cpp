/* C++ program to detect loop in linked list using hashing*/

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head = NULL;
Node* tail = NULL;

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

void detect_loop_hash(){
	unordered_map<Node*, int>umap;
	Node* temp = head;
	while(temp!=NULL){
		umap[temp]++;
		if(umap[temp] > 1){
			cout<<"There is loop in the linked list"<<endl;
			cout<<"The value where loop is present is "<<temp->data<<endl;
			break;
		}
		temp = temp->next;
	}
	if(temp == NULL){
		cout<<"There is no loop in the linked list"<<endl;
	}
}

int main(){
	add_end(1);
	add_end(2);
	add_end(3);
	add_end(4);
	add_end(5);
	add_end(6);
	tail->next = head->next; // for making loop
	detect_loop_hash();
	return 0;
}


