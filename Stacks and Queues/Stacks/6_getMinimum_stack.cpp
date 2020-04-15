/* C++ program to design a stack such that getMinimum() should be O(1) time
and O(1) space. */ 

#include<iostream>
using namespace std;

int stack[100];
int minele;
int top = -1;
int MAX = 100;

void push(int data){
	if(top == MAX-1)
		return;
	if(top == -1){
		stack[++top] = data;
		minele = data;
	}
	else{
		if(data < minele){
			stack[++top] = 2*data - minele;
			minele = data;
		}else{
			stack[++top] = data;
		}
	}
}

int pop(){
	int data;
	if(top == -1)
		return -1;
	if(stack[top] < minele){
		data = minele;
		minele = 2*minele - stack[top];
	}
	else
		data = stack[top];
	
	top--;
	return data;
}

int get_minimum(){
	if(top > -1)
		return minele;
}

int main(){
	
	push(2);
	push(1);
	push(4);
	cout<<"Current minimum element in stack is "<<get_minimum()<<endl;
	push(6);
	push(-1);
	push(7);
	cout<<"Current minimum element in stack is "<<get_minimum()<<endl;
	cout<<pop()<<" is popped out from stack"<<endl;
	cout<<pop()<<" is popped out from stack"<<endl;
	cout<<"Current minimum element in stack is "<<get_minimum()<<endl;
	
	return 0;
}

