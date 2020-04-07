/* C++ program to split the linked list into k consecutive linked list parts.*/

#include<iostream>
#include<vector>
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
	if(!head){
		head = temp;
		tail = temp;
		return;
	}
	tail->next = temp;
	tail = temp;
}

void split_k(vector<Node*> &k_heads, int k, int N){
	int i, remainder = N%k, num = N/k;
	Node* temp = head;
	Node* temp2;
	while(temp){
		k_heads.push_back(temp);
		for(i = 0; i<num-1; i++){
			temp = temp->next;
		}
		if(remainder > 0 && temp != NULL){
			temp = temp->next;
			remainder--;
		}
		temp2 = temp;
		temp = temp->next;
		temp2->next = NULL;
	}
}

void print_list(vector<Node*> &k_heads){
	Node* temp;
	for(int i = 0; i<k_heads.size(); i++){
		temp = k_heads.at(i);
		while(temp){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}
}

int main(){
	int N, k, i, d;
	cout<<"Enter the number of elements in the list"<<endl;
	cin>>N;
	cout<<"Enter the elements"<<endl;
	for(i=0;i<N;i++){
		cin>>d;
		add_end(d);
	}
	cout<<"Enter the value of k"<<endl;
	cin>>k;
	vector<Node*> k_heads;
	split_k(k_heads, k, N);
	cout<<"The k lists after splitting the main list are"<<endl;
	print_list(k_heads);
	return 0;
}




