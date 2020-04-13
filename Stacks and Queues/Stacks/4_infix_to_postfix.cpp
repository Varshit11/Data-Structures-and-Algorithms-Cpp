/* C++ program to convert infix to postfix expression 
Implement this without using STL */

#include<iostream>
#include<ctype.h> // for using isdigit()
using namespace std;

class Node{
	public:
		char c;
		Node* next;
};

Node* top = NULL;

bool isempty(){
	if(!top){
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
	if(isempty())
		return 'q';
	Node* temp = top;
	char data = temp->c;
	top = top->next;
	temp->next = NULL;
	delete temp;
	return data;
}

int get_priority(char d){
	if(d == '(')
		return 0;
	if(d == '+' || d == '-')
		return 1;
	if(d == '*' || d == '/')
		return 2;
}

void infix_to_postfix(string &s1, string &s2){
	s1 = s1+')';
	push('(');
	char data;
	int i = 0, priority;
	while(i < s1.size()){
		if(isdigit(s1[i])) // if its digit just add to the final expression..
			s2 = s2 + s1[i];
		else if(s1[i] == '(') // if ( then push it on stack
			push(s1[i]);
		else if(s1[i] == ')'){ // if ) then pop all element until ( is found
			while(1){
				data = pop();
				if(data == '(')
					break;
				s2 = s2 + data; // after popping add the operator in final expresion
			}
		}else{
			priority = get_priority(s1[i]); //if operator find its priority
			while(1){
				if(get_priority(top->c) >= priority){ // pop all element from the stack until the priority of element is greater than that of top element
					data = pop();
					s2 = s2 + data;
				}else{ // if priority of element is already greater than top, then just push the operator in stack.
					push(s1[i]);
					break;
				}
			}
		}
		++i; // increment the string index
	}
}

int main(){
	string s1;
	cout<<"Enter the infix expression"<<endl;
	cin>>s1;
	string s2;
	infix_to_postfix(s1, s2);
	cout<<"The postfix expression is"<<endl;
	cout<<s2<<endl;
	return 0;
}

