/* C++ program to print the right view of the binary tree without recusion */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

vector<int> right_view(Node* root){
	queue <Node*> q;
	vector <int> v;
	Node* temp;
	int d;
	q.push(root);
	while(!q.empty()){
		temp = q.back();
		v.push_back(temp->data);
		d = q.size();
		while(d--){
			temp = q.front();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			q.pop();
		}
	}
	return v;
}

int main(){
	root = create_node(1);
	root->left = create_node(2);
	root->right = create_node(3);
	root->left->right = create_node(5);
	root->right->right = create_node(4);
	
	vector<int> v = right_view(root);
	cout<<"The right view of the binary tree is "<<endl;
	vector <int>:: iterator it;
	for(it = v.begin(); it<v.end(); it++){
		cout<<*it<<" ";	
	}
	return 0;
}

