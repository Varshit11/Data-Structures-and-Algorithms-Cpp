/* C++ program to merge k sorted linked lists and return it as one sorted list.
For ex. if k = 3, list1 is 1->4->5, list2 is 1->3->4 and list3 is 2->6,
the output should be 1->1->2->3->4->4->5->6 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* final_head;

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

Node* find_min(vector <Node*> &temp){
	int index;
	int k = temp.size();
	Node* min_point;
	for(int j = 0; j<k; j++){
		if(temp[j]){
			min_point = temp.at(j);
			index = j;
			break;
		}
	}
	
	for(int i = 0; i<k; i++){
		if(temp[i]){
			if(min_point->data > temp[i]->data){
			min_point = temp[i];
			index = i;
			}
		}
	}
	temp.at(index) = temp.at(index)->next;
	return min_point;
}

bool is_null(vector <Node*> &temp){
	int k = temp.size();
	bool t = true;
	for(int i = 0; i< k; i++){
		if(temp[i]){
			t = false;
			break;
		}
	}
	return t;
}

void merge_klists(vector <Node*> &heads){
	vector <Node*> temp = heads;
	final_head = find_min(temp);
	Node* temp2 = final_head;
	
	while(!is_null(temp)){
		temp2->next = find_min(temp);
		temp2 = temp2->next;
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
	int k, i, num, j, d;
	cout<<"Enter the number of lists"<<endl;
	cin>>k;
	vector <Node*> heads;
//	vector <Node*> tail;
	for(i=0; i<k;i++){
		Node* temp = NULL; // for heads
		Node* temp2 = NULL; // for tails
		cout<<"Enter the number of elements in list "<<i+1<<endl;
		cin>>d;
		cout<<"Enter the elements of list "<<i+1<<endl;
		for(j=0; j<d; j++){
			cin>>num;
			add_end(&temp, &temp2, num);
		}
		heads.push_back(temp);
	}
	
	merge_klists(heads);
	cout<<"After merging "<<k<<" sorted lists, the final merged list is"<<endl;
	print_list(final_head);
	return 0;
}

