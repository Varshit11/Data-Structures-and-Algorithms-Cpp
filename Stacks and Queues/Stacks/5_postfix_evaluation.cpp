/* C++ program to evaluate postfix expression. 
Implement this without using STL */

#include<iostream>
#include<ctype.h> // for using isdigit()
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

Node* top = NULL;

bool isempty(){
	if(!top)
		return true;
	return false;
}

void push(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->next = top;
	top = temp;
}

int pop(){
	if(isempty())
		return -1; // just a random integer to signify it is empty, we can use exit(1) or return any other macros..
	Node* temp = top;
	top = top->next;
	int data = temp->data;
	delete temp;
	return data;
}

int evaluate(int d1, int d2, char c){
	if(c == '+')
		return d2+d1;
	if(c == '-')
		return d2-d1;
	if(c == '*')
		return d2*d1;
	if(c == '/')
		return d2/d1;
}

int postfix_evaluate(string &s){
	int ans, d1, d2;
	for(int i = 0; i<s.size(); i++){
		if(isdigit(s[i]))
			push((int)(s[i]-48));
		else{
			d1 = pop();
			d2 = pop();
			if(d1 == -1 || d2 == -1){
				cout<<"The postfix expression is invalid"<<endl;
				exit(1);
			}
			ans = evaluate(d1, d2, s[i]);
			push(ans);
		}	
	}
	if(top->next){
		cout<<"The postfix expression is invalid"<<endl;
		exit(1);
	}
	return top->data;
}

int main(){
	string s1;
	cout<<"Enter the postfix expression to be evaluated"<<endl;
	cin>>s1;
	
	int ans = postfix_evaluate(s1);	
	cout<<"The postfix evaluates to "<<endl;
	cout<<ans<<endl;
}

