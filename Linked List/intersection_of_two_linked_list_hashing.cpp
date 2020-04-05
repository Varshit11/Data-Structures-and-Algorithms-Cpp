// find intersection node of 2 linked list using hashing

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

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

void intersection(Node* head1, Node* head2){
	unordered_map<Node*, int> umap;
	Node* temp = head1;
	while(temp!= NULL){
		umap[temp]++;
		temp = temp->next;
	}
	temp = head2;
	while(temp!=NULL){
		umap[temp]++;
		if(umap[temp]>1){
			cout<<"The value at intersection node of given linked lists is "<<temp->data<<"\n";
			break;
		}
		temp = temp->next;
	}
	if(temp == NULL){
		cout<<"There is no intersection node in the given linked lists\n";
	}
}

int main(){
	Node* head1 = NULL;
	Node* tail1 = NULL;
	Node* head2 = NULL;
	Node* tail2 = NULL;
	
	// 1st list 1 2 3 4 5 6 7
	add_end(&head1, &tail1, 1);
	add_end(&head1, &tail1, 2);
	add_end(&head1, &tail1, 3);
	add_end(&head1, &tail1, 4);
	add_end(&head1, &tail1, 5);
	add_end(&head1, &tail1, 6);
	add_end(&head1, &tail1, 7);
	
	// 2nd list 10 9 8 4 5 6 7
	add_end(&head2, &tail2, 10);
	add_end(&head2, &tail2, 9);
	add_end(&head2, &tail2, 8);
	
	tail2->next = head1->next->next->next; // making the intersection
	intersection(head1, head2);
	return 0;
}

