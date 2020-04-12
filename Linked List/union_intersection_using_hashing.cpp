/* C++ program to find union and intersection of 2 linked lists.
Assumption - A particular linked list has unique values 
Implement using hashing based approach */

#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* head_union = NULL;
Node* head_intersection = NULL;

void add_beg(Node** head, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

void find_union_intersection(){
	unordered_map <int, int> umap;
	Node* temp = head1;
	while(temp!=NULL){
		add_beg(&head_union, temp->data);
		umap[temp->data]++;
		temp = temp->next;
	}
	temp = head2;
	while(temp != NULL){
		umap[temp->data]++;
		if(umap[temp->data] >1){
			add_beg(&head_intersection, temp->data);
		}else{
			add_beg(&head_union, temp->data);
		}
		temp = temp->next;
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
	int n1, n2, i, num;
	cout<<"Enter the number of elements in list1 and list2"<<endl;
	cin>>n1>>n2;
	cout<<"Enter the elements of first list in reverse order"<<endl;
	for(i=0;i<n1;i++){
		cin>>num;
		add_beg(&head1, num);
	}
	cout<<"Enter the elements of second list in reverse order"<<endl;
	for(i=0;i<n2;i++){
		cin>>num;
		add_beg(&head2, num);
	}
	find_union_intersection();
	
	cout<<"The union of both lists is"<<endl;
	print_list(head_union);
	cout<<"The intersection of both lists is"<<endl;
	print_list(head_intersection);
	
	return 0;
}

