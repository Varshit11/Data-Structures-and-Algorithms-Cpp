/* C++ program to Merge multiple list and flatten them..*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* down;
};

class Node2{
	public:
		Node* p;
		Node2* right;
};

Node* tail; // we dont need Node* head as Node2* head2 takes care of that
Node2* head2;
Node2* tail2;
Node* head3; // will store the final output..

void add_end_node2(Node2** head, Node2** tail, int data){
	Node2* temp = new Node2;
	temp->p = new Node;
	temp->p->data = data;
	temp->right = NULL;
	temp->p->down = NULL;
	if(*head == NULL){
		*head = temp;
		*tail = temp;
		return;
	}
	(*tail)->right = temp;
	*tail = temp;
}

void add_end_node(Node2** t, Node** tail, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->down = NULL;
	if((*t)->p->down == NULL){
		(*t)->p->down = temp;
		*tail = temp;
		return;
	}
	(*tail)->down = temp;
	*tail = temp;
}

Node* merge(Node* temp1, Node* temp2){
	Node* final;
	Node* temp3;
	if(temp1->data <= temp2->data){
		final = temp1;
		temp1 = temp1->down;
	}else{
		final = temp2;
		temp2 = temp2->down;
	}
	temp3 = final;
	while(temp1 && temp2){
		if(temp1->data <= temp2->data){
			temp3->down = temp1;
			temp1 = temp1->down;
		}else{
			temp3->down = temp2;
			temp2 = temp2->down;
		}
		temp3 = temp3->down;
	}
	while(temp1){
		temp3->down = temp1;
		temp1 = temp1->down;
		temp3 = temp3->down;
	}
	while(temp2){
		temp3->down = temp2;
		temp2 = temp2->down;
		temp3 = temp3->down;
	}
	return final;
}

void flatten_lists(){
	Node2* temp = head2;
	Node* temp1 = temp->p;
	Node* temp2;
	temp = temp->right;
	while(temp){
		temp2 = temp->p;
		temp = temp->right;
		head3 = merge(temp1, temp2);
		temp1 = head3;
	}
}

void print_list(Node* head){
	Node* temp = head;
	while(temp){
		cout<<temp->data<<" ";
		temp = temp->down;
	}
	cout<<endl;
}

int main(){
	int num_list, N, i, j, num, num1;
	cout<<"Enter the number of lists"<<endl;
	cin>>num_list;
	for(i=0;i<num_list;i++){
		cout<<"Enter the number of elements in list "<<i+1;
		cout<<" and also enter the first element of this list"<<endl;
		cin>>N>>num1;
		add_end_node2(&head2, &tail2, num1);
		cout<<"Enter the rest of the elements of this list"<<endl;
		for(j=1;j<N; j++){
			cin>>num;
			add_end_node(&tail2, &tail, num);
		}
	}
	if(N == 1){
		cout<<"The list is already sorted, no need to merge"<<endl;
		head3 = head2->p;
	}
	else if(N == 2){
		head3 = merge(head2->p, head2->right->p);
	}
	else{
		flatten_lists();
	}
	cout<<"The final flattened list is"<<endl;
	print_list(head3);
	return 0;
}

