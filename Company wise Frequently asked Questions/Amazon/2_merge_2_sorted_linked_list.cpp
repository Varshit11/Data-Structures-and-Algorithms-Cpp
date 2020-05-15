/* C++ program to merge 2 sorted lists 
Problem statement - https://leetcode.com/problems/merge-two-sorted-lists/
*/

#include<iostream>
using namespace std;

class ListNode{
	public:
		int val;
		ListNode* next;
};

void add_end(ListNode** head, ListNode** tail, int data){
	ListNode* temp = new ListNode;
	temp->val = data;
	temp->next = NULL;
	if(*head == NULL){
		*head = temp;
		*tail = temp;
		return;
	}
	(*tail)->next = temp;
	*tail = temp;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1) return l2;
    else if(!l2) return l1;
    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* temp3;
    ListNode* ans;
    if(temp1->val <= temp2->val){
        ans = temp1;
        temp1 = temp1->next;
    }else{
        ans = temp2;
        temp2 = temp2->next;
    } 
    temp3 = ans;
    while(temp1 && temp2){
        if(temp1->val <= temp2->val){
            temp3->next = temp1;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        else{
            temp3->next = temp2;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
    }
    while(temp1){
        temp3->next = temp1;
        temp1 = temp1->next;
        temp3 = temp3->next;
    }
    while(temp2){
        temp3->next = temp2;
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    return ans;
}

void print_list(ListNode* head){
	ListNode* temp = head;
	while(temp){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	ListNode* head1 = NULL;
	ListNode* tail1 = NULL;
	ListNode* head2 = NULL;
	ListNode* tail2 = NULL;
	add_end(&head1, &tail1, 1);
	add_end(&head1, &tail1, 2);
	add_end(&head1, &tail1, 4);
	
	add_end(&head2, &tail2, 1);
	add_end(&head2, &tail2, 3);
	add_end(&head2, &tail2, 4);
	
	ListNode* ans = mergeTwoLists(head1, head2);
	cout<<"After merging sorted linked list the final list is "<<endl;
	print_list(ans);
	return 0;
}

