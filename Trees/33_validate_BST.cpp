/* C++ program to validate the binary search tree. 
Problem link - https://leetcode.com/problems/validate-binary-search-tree/
*/

#include<iostream>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
		Node(int data): val(data), left(NULL), right(NULL){}
};

Node* root = NULL;

bool isValidBST(Node* root, long low=LONG_MIN, long high=LONG_MAX) {
	return !root ? true : root->val > low && root->val < high ? isValidBST(root->left, low, root->val) && 
					isValidBST(root->right, root->val, high) : false;
}

int main(){
	root = new Node(5);
	root->left = new Node(1);
	root->right = new Node(4);
	root->right->left = new Node(3);
	root->right->right = new Node(6);
	
	isValidBST(root) ? cout<<"Valid BST"<<endl : cout<<"Not a BST"<<endl;
	
	Node* root2 = new Node(2);
	root2->left = new Node(1);
	root2->right = new Node(3);
	isValidBST(root2) ? cout<<"Valid BST"<<endl : cout<<"Not a BST"<<endl;	
	
	return 0;
}

