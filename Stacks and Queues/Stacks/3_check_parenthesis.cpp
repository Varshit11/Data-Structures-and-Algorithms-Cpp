/* C++ program for parenthesis check using stack 
We will implement it without using STL in this code*/

#include<iostream>
using namespace std;

class Node{
	public:
		char c;
		Node* next;
};

Node* top = NULL;

bool isempty(){
	if(top == NULL){
		return true;
	}
	return false;
}

void push(char data){
	Node* temp = new Node;
	temp->c = data;
	temp->next = top;
	top = temp;
}

char pop(){
	if(isempty()){
		return 'q';
	}
	char data = top->c;
	Node* temp = top;
	top = top->next;
	temp->next = NULL;
	delete temp;
	return data;
}

bool check_parenthesis(string &s){
	char data;
	bool f = true;
	for(int i = 0; i<s.size(); i++){
		if(s.at(i) == '[' || s.at(i) == '{' || s.at(i) == '('){
			push(s.at(i));
		}else if(s.at(i) == ']' || s.at(i) == '}' || s.at(i) == ')'){
			data = pop();
			if(s.at(i) == ']')
				s.at(i) = '[';
			if(s.at(i) == '}')
				s.at(i) = '{';
			if(s.at(i) == ')')
				s.at(i) = '(';

			if(data - 'q' == 0){
				f = false;
				break;
			}else if(s.at(i) - data == 0){
				continue;
			}else{
				f = false;
				break;
			}
		}else{
			continue;
		}
	}
	return f;
}


int main(){
	string s;
	cout<<"Enter the expression as a string"<<endl;
	cin>>s;
	bool f = check_parenthesis(s);
	if(f){
		cout<<"The expression is balanced expression"<<endl;
	}else{
		cout<<"The expression is not balanced expression"<<endl;
	}
	return 0;
}
