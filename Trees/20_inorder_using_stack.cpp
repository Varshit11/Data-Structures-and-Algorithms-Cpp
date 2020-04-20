/* C++ program to implement inorder traversal using stack. No recursion */

#include<iostream>
#include<stack>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
stack <Node*> s;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(Node* root){
	Node* temp = root;
	s.push(root);
	while(!s.empty()){
		while(temp!=NULL){ // go left and push till temp is NULL
			temp = temp->left;
			s.push(temp);
		}
		temp = s.top(); // now take the top node of stack
		s.pop(); // pop the top element
		while(!temp && !s.empty()){ // it may happen the top element is NULL so we will continue to pop until we find non null node
			temp = s.top();
			s.pop();
		}
		if(temp){ // if we get non null node, we will print the data and push the right child into stack
			cout<<temp->data<<" ";
			s.push(temp->right);
			temp = temp->right;
		}
	}
}

int main(){
	root = create_node(10);
	root->left = create_node(6);
	root->right = create_node(15);
	root->left->left = create_node(4);
	root->left->right = create_node(7);
	root->left->right->left = create_node(6);
	root->left->right->right = create_node(9);
	root->right->left = create_node(13);
	root->right->right = create_node(20);
	
	cout<<"The inorder traversal of the tree is "<<endl;
	inorder(root);
	return 0;
}

