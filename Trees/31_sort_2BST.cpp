/* C++ program to sort 2 binary search tree using iterative approach */

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root1 = NULL;
Node* root2 = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void sort_2bst(Node* root1, Node* root2, vector<int> &v){
	stack<Node*> s1;
	stack<Node*> s2;
	while(root1 || root2 || !s1.empty() || !s2.empty()){
		while(root1){
			s1.push(root1);
			root1 = root1->left;
		}
		while(root2){
			s2.push(root2);
			root2 = root2->left;
		}
		if(s2.empty() || (!s1.empty() && (s1.top())->data <= (s2.top())->data)){
			root1 = s1.top();
			s1.pop();
			v.push_back(root1->data);
			root1 = root1->right;
		}else{
			root2 = s2.top();
			s2.pop();
			v.push_back(root2->data);
			root2 = root2->right;
		}
	}
}

int main(){
	root1 = create_node(2);
	root1->left = create_node(1);
	root1->right = create_node(33);
	root1->right->left = create_node(25);
	root1->right->right = create_node(40);
	
	root2 = create_node(1);
	root2->left = create_node(0);
	root2->right = create_node(2);
	root2->right->right = create_node(3);
	
	vector <int> v;
	sort_2bst(root1, root2, v);
	cout<<"The sorted array of these 2 trees is "<<endl;
	for(int i = 0; i<v.size(); i++)
		cout<<v[i]<<" ";
	
	return 0;
}

