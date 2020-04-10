/* C++ program to add 2 numbers stores as list..
for ex. if num1 is 563 then it is stores as 5->6->3, if num2 =234 then it is 
stores as 2->6->4, the final output should be addition of these, i.e 
the output should be 827 and stored as 8->2->7 */

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* head1 = NULL;
Node* head2 = NULL;
Node* head3 = NULL;

void add_beg(Node** head, int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
}

int add(Node* head1, Node* head2){
	int sum, carry = 0;
	if(head1->next && head2->next){
		carry = add(head1->next, head2->next);
	}
	sum = head1->data + head2->data + carry;
	carry = sum/10;
	add_beg(&head3, sum%10);
	return carry;
}

int add_remaining(Node* temp1, Node* temp2, int c){
	int carry = 0, sum;
	if(temp1->next != temp2){
		carry = add_remaining(temp1->next, temp2, c);
	}
	if(temp1->next == temp2){
		sum = temp1->data + c;
		carry = sum/10;
		add_beg(&head3, sum%10);
		return carry;
	}else{
		sum = temp1->data + carry;
		carry = sum/10;
		add_beg(&head3, sum%10);
		return carry;
	}
}

int make_list(Node** head, int data){
	int temp = data, num, count=0;
	while(temp>0){
		num = temp%10;
		add_beg(head, num);
		temp /= 10;
		count++;
	}
	return count;
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
	int a, b, temp, i, c, c2;
	cout<<"Enter the numbers to add"<<endl;
	cin>>a>>b;
	
	// making the desired linked list of number
	int count1 = make_list(&head1, a); // count digits in a
	int count2 = make_list(&head2, b); // count digits in b
	
	Node* temp1 = head1;
	Node* temp2 = head2;
	
	if(count1 > count2){
		for(i = 0; i<count1-count2;i++){
			temp1 = temp1->next;
		}
		c = add(temp1, head2);
		c2 = add_remaining(head1, temp1, c);
	}
	else if(count2 > count1){
		for(i=0; i<count2-count1; i++){
			temp2 = temp2->next;
		}
		c = add(head1, temp2);
		c2 = add_remaining(head2, temp2, c);
	}
	else{
		c2 = add(head1, head2);
	}
	
	if(c2 > 0){
		add_beg(&head3, c2);
	}
	cout<<"The addition of 2 numbers a and b in reverse order is"<<endl;
	print_list(head3); //should print the addition of a and b
	return 0;
}

