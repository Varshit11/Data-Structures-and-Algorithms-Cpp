/* C++ program to solve binary tree pruning problem.
Problem link - https://leetcode.com/problems/binary-tree-pruning/
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

Node* pruneTree(Node* root) {
    if(!root)
        return NULL;
    if(root->val == 1){
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        return root;
    }
    else if(root->val == 0){
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(!root->left && !root->right)
            return NULL;
        else
            return root;
    }
    return root;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){
	root = new Node(1);
	root->left = new Node(1);
	root->right = new Node(0);
	root->left->left = new Node(1);
	root->left->right = new Node(1);
	root->left->left->left = new Node(0);
	root->right->left = new Node(0);
	root->right->right = new Node(1);
	
	root = pruneTree(root);
	cout<<"The inorder traversal of the pruned tree is "<<endl;
	inorder(root);
	return 0;
}

