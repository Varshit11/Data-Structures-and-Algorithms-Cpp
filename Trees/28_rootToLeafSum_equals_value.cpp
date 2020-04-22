/* C++ program to 28. Given a binary tree and a sum, 
determine if the tree has a root-to-leaf path such that adding up all the values
along the path equals the given sum. 
Problem link - https://leetcode.com/problems/path-sum/
*/

#include<iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
};

Node* root = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool hasPathSum(Node* root, int sum, int i=0) {
    if(!root)
    	return false;
    if(!root->left && !root->right && root->val + i == sum)
        return true;
        
    return hasPathSum(root->left, sum, i+root->val) || hasPathSum(root->right, sum, i+root->val);
}

int main(){
	root = create_node(5);
	root->left = create_node(4);
	root->right = create_node(8);
	root->left->left = create_node(11);
	root->left->left->left = create_node(7);
	root->left->left->right = create_node(2);
	root->right->left = create_node(13);
	root->right->right = create_node(4);
	root->right->right->right = create_node(1);
	
	if(hasPathSum(root,22))
		cout<<"There is a path from root to leaf with sum 22"<<endl;
	else
		cout<<"There is no path from root to leaf with sum 22"<<endl;
	
	return 0;
}

