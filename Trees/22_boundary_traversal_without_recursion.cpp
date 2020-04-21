/* C++ program to do boundary order traversal without recursion */

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
queue <Node*> q;
stack <int> s;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void boundary_traversal(Node* root){
	if(!root)
		return;
	Node* temp;
	Node* temp2;
	q.push(root);
	while(!q.empty()){
		temp = q.front();
		temp2 = q.back();
		if(temp == temp2) // if its root as front and back will be same
			cout<<temp->data<<" ";
		else if(temp->left || temp->right){ // this condition is only needed to avoid printing of the last level front and back, as they are leaf node and they will be handled in the next while loop
			cout<<temp->data<<" ";
			s.push(temp2->data);
		}
		int c = q.size(); // number of nodes in a particular level. 
		while(c--){
			temp = q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			if(!temp->left && !temp->right) // if its leaf node then print in left to right order
				cout<<temp->data<<" ";
			q.pop();	
		}
	}
	while(!s.empty()){ // since we want to print the right boundary elements in opposite order we have stored it in stack and now we will just pop the element out
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->right = create_node(4);
	root->left->right->left = create_node(7);
	root->left->right->right = create_node(8);
	root->right->left = create_node(5);
	root->right->left->left = create_node(9);
	root->right->left->right = create_node(10);
	root->right->right = create_node(6);
	root->right->right->left = create_node(11);
	
	cout<<"The boundary traversal of this binary tree is "<<endl;
	boundary_traversal(root);
	
	return 0;	
}


