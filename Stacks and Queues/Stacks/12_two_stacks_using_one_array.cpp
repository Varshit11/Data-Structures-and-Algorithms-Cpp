/* C++ program to implement 2 stacks in a single array */

#include<iostream>
using namespace std;
#define MAX 10 

int top1 = -1; // growing stack1 from start of array
int top2 = MAX; // growing stack2 from the end of array
int stack[10];

bool isfull(){
	if(top1+1 == top2)
		return true;
	return false;
}

bool isempty(int d){
	if(d == 1 && top1 == -1)
		return true;
	else if(d == 2 && top2 == MAX)
		return true;
	else
		return false;
}

void push(int d, int data){
	if(d == 1 && !isfull())
		stack[++top1] = data;
	else if(d == 2 && !isfull())
		stack[--top2] = data;
	else
		cout<<"Stack overflow"<<endl;
}

int pop(int d){
	if(!isempty(d) && d == 1)
		return stack[top1--];
	else if(!isempty(d) && d == 2)
		return stack[top2++];
	else
		return INT_MIN;
}

int main(){
	int data;
	push(1,1);
	
	data = pop(1);
	(data == INT_MIN) ? cout<<"Stack 1 is empty"<<endl : cout<<data<<" is popped"<<endl;
	data = pop(1);
	(data == INT_MIN) ? cout<<"Stack 1 is empty"<<endl : cout<<data<<" is popped"<<endl;
	
	push(1,1);
	push(1,2);
	push(1,3);
	push(1,4);
	
	data = pop(2);
	(data == INT_MIN) ? cout<<"Stack 2 is empty"<<endl : cout<<data<<" is popped"<<endl;
	
	push(2,5);
	push(2,6);
	push(2,7);
	push(2,8);
	push(2,9);
	push(2,10);
	push(2,11); // print stack overflow
	
	return 0;
	
}

