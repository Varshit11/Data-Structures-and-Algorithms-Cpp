/* C++ program to reverse a stack using recursion.*/

#include<iostream>
using namespace std;
#define MAX 100

int stack[100];
int top = -1;

void push(int data){
	if(top == MAX-1)
		return;
	stack[++top] = data;
}

int pop(){
	if(top == -1)
		return -1;
	return stack[top--];
}

void insert(int data){
	if(top == -1){
		push(data);
		return;
	}
	int x = pop();
	insert(data);
	push(x);
}

void reverse(){
	if(top > -1){
		int data = pop();
		reverse();
		insert(data);
	}
}

int main(){
	int d;
	// making the stack 4 3 2 1 with top pointing at 4
	push(1);
	push(2);
	push(3);
	push(4);
	reverse();
	// now we will pop every element to see if we have reversed the stack
	while((d = pop())!=-1) // should print 1 2 3 4
		cout<<d<<" ";
	
	return 0;
}

