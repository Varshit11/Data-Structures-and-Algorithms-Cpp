/* C++ program to implement stack using queue. */

#include<bits/stdc++.h>
using namespace std;
#define MAX 10
// for this problem I am implementing simple queue, no circular queue
// you can solve this problem using circular queue also, to make use of space
int queue1[10];
int queue2[10];
int front1 = -1;
int rear1 = -1;
int front2 = -1;
int rear2 = -1;

bool isfull(int d){
	if(d == 1)
		return (rear1 == MAX) ? true : false;
	else
		return (rear2 == MAX) ? true : false;
}

bool isempty(int d){
	if(d == 1)
		return (front1>rear1 || (front1 == -1 && rear1 == -1))? true:false;
	else
		return (front2>rear2 || (front2 == -1 && rear2 == -1))? true:false;
}

void enqueue(int d, int data){
	if(d == 1 && !isfull(d)){
		queue1[++rear1] = data;
		if(front1 == -1)
			front1 = 0;
	}	
	else if(d == 2 && !isfull(d)){
		queue2[++rear2] = data;
		if(front2 == -1){
			front2 = 0;
		}
	}	
	else
		cout<<"Queue is full"<<endl;
}

int dequeue(int d){
	if(!isempty(d) && d == 1)
		return queue1[front1++];
	else if(!isempty(d) && d == 2)
		return queue2[front2++];
	else
		return INT_MIN;
}

void push(int data){ // here push means enqueue
	enqueue(1, data);
}

int pop(){ // here pop is made costly
	int data, ans;
	if(!isempty(1)){
		while(front1 != rear1){
			data = dequeue(1);
			enqueue(2, data);
		}
		ans = dequeue(1);
		front1 = -1;
		rear1 = -1;
		while(!isempty(2)){
			data = dequeue(2);
			enqueue(1, data);
		}
		front2 = -1;
		rear2 = -1;
		return ans;
	}else{
		return INT_MIN;
	}
}

int main(){
	int data;
	push(1);
	push(2);
	
	data = pop(); // data is 2
	(data == INT_MIN)?cout<<"The stack is empty"<<endl:cout<<data<<" is popped"<<endl; 
	data = pop(); // data is 1
	(data == INT_MIN)?cout<<"The stack is empty"<<endl:cout<<data<<" is popped"<<endl; 
	data = pop(); // data is INT_MIN since stack is empty
	(data == INT_MIN)?cout<<"The stack is empty"<<endl:cout<<data<<" is popped"<<endl; 

	push(1);
	push(2);
	push(3);
	push(4);
	data = pop(); // data is 4
	(data == INT_MIN)?cout<<"The stack is empty"<<endl:cout<<data<<" is popped"<<endl; 
	data = pop(); // data is 3
	(data == INT_MIN)?cout<<"The stack is empty"<<endl:cout<<data<<" is popped"<<endl; 
	
	return 0;
}

