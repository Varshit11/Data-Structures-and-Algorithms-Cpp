// C++ program to find intersection node of 2 linked lists.

#include<iostream>
#include<cstdlib> // for using abs() function
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

int count_nodes(Node* head){
	Node* temp = head;
	int count = 0;
	while(temp!= NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

int find_intersection(Node* temp1, Node* temp2, int diff){
	for(int i = 1; i< diff; i++){
		temp1 = temp1->next;
	}
	while(temp1 != 0 && temp2 != 0){
		if(temp1 == temp2){
			return temp1->data;
			break;
		}else{
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	if(temp1 == NULL || temp2==NULL){
		return -1;
	}
}

void intersection(Node* head1, Node* head2){
	int count1 = count_nodes(head1);
	int count2 = count_nodes(head2);
	int diff = count1-count2;
	int ans;
	if(diff >= 0){
		ans = find_intersection(head1, head2, diff);
	}else{
		ans = find_intersection(head2, head1, abs(diff));
	}
	if(ans == -1){
		cout<<"There is no intersection node in these linked lists"<<endl;
		return;
	}
	cout<<"The value stored in intersection node of these linked lists is "<<ans<<endl;
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

