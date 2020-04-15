/* C++ program to implement circular queues using arrays..*/

#include<iostream>
using namespace std;
int queue[5];
int head = -1;
int tail = -1;
int MAX = 5;

void enqueue(int data){
	if(head == -1 && tail == -1){
		head = 0;
		tail = 0;
		queue[head] = data;
		return;
	}
	if((tail+1)%MAX == head){
		cout<<"Can't enqueue "<<data<<" as the queue is full"<<endl;
		return;
	}
	tail = (tail+1)%MAX;
	queue[tail] = data;
}

int dequeue(){
	int data;
	if((head == -1 && tail == -1)){
		return -1;
	}
	if(head == tail){
		data = queue[head];
		head = -1;
		tail = -1;
		return data;
	}
	data = queue[head];
	head = (head+1)%MAX;
	return data;
}

int main(){
	int data;
	enqueue(1);
	enqueue(2);
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
//	data = dequeue();
//	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
//	data = dequeue();
//	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
	
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;	
	
	data = dequeue();
	(data == -1)?cout<<"Can't dequeue, the queue is empty"<<endl : cout<<data<<" is dequeued"<<endl;		
	
	return 0;	
}

