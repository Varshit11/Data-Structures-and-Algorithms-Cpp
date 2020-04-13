/* C++ program to implement a stack using arrays. */

#include<iostream>
using namespace std;

int stack[100];
int top = -1;
int MAX = 100;

bool isempty(){
	if(top == -1){
		return true;
	}else{
		return false;
	}
}

bool isfull(){
	if(top == MAX-1){
		return true;
	}else{
		return false;
	}
}

int pop(){
	if(isempty()){
		return -1;
	}
	return stack[top--];
}

void push(int data){
	if(isfull()){
		return;
	}
	stack[++top] = data;
}

int peek(){
	if(isempty()){
		return -1;
	}
	return stack[top];
}

int main(){
	int i;
	push(1);
	push(2);
	push(3);
	cout<<"Now top element points to "<<peek()<<endl;
	push(4);
	i = pop();
	i = pop();
	i = pop();
	if(i != -1){
		cout<<"Now "<<i<<" is popped out"<<endl;
	}
	return 0;
}

