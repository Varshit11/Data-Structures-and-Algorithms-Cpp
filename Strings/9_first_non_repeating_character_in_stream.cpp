/* C++ program to Find first non-repeating character in a stream. The characters will be
coming as a stream so the size is not fixed. 
*/

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

// for doubly linked list queue
class Node{
	public:
		char c;
		Node* next;
		Node* prev;
};

Node* front = NULL;
Node* rear = NULL;

Node* insert(char c){
	Node* temp = new Node;
	temp->c = c;
	temp->next = NULL;
	temp->prev = NULL;
	if(front == NULL){
		front = temp;
		rear = temp;
		return temp;
	}
	rear->next = temp;
	temp->prev = rear;
	rear = temp;
	return temp;
}

void delete_node(Node* temp){
	Node* temp2;
	if(temp == front) { // delete first element
		front = front->next;
		if(front) front->prev = NULL;
		temp->next = NULL;
	}
	else if (temp == rear){ // delete last element
		rear = temp->prev;
		temp->prev = NULL;
		rear->next = NULL;
	}
	else{ // delete any element between first and last
		temp2 = temp->prev;
		temp2->next = temp->next;
		temp->next->prev = temp->prev;
	}
	delete temp;
}

char find_front(){ // just return the front character as it is first non repeating character
	if(!front) return ' ';
	return front->c;
}

void find_first_non_repeating_stream(){
	string str;
	map<char, pair<Node*, bool>> m;
	char v;
	Node* temp;
	pair<Node*, int> t;
	while(true){ // we will take character input indefinitely until user stops..
		cout<<"Enter the character, Ctrl + C to exit "<<endl;
		cin>>v;
		str+=v;
		if(m.find(v) == m.end()){ // if the character is seen first time then insert in queue
			temp = insert(v);
			m[v] = make_pair(temp, true);
		}
		else if(m.find(v) != m.end()){
			t = m[v];
			temp = t.first;
			if(t.second && temp){ // if already there is character and this character is present in queue
				delete_node(temp);
				t.first = NULL;
			}
		}
		if(find_front() == ' ')
			cout<<"Right now there are no non repeating characters "<<endl;
		else
			cout<<"The first non repeating character till now is "<<find_front()<<endl;
	}
}

int main(){
	find_first_non_repeating_stream();
	return 0;
}

