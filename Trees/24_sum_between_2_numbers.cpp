/* C++ program to find the range sum of Binary search tree.
Problem link - https://leetcode.com/problems/range-sum-of-bst/
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
int sum = 0;

Node* create_node(int data){
	Node* temp = new Node;
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}


int rangeSumBST(Node* root, int L, int R) {
        int i;
        if(!root)
            return 0;
        i = rangeSumBST(root->left, L, R);
        i = rangeSumBST(root->right, L, R);
        if(root->val >= L && root->val <= R){
            sum +=  root->val;
        }
        return sum;
}

int main(){
	root = create_node(2);
	root->left = create_node(1);
	root->left->right = create_node(4);
	root->right = create_node(3);
	root->right->right = create_node(7);
	
	cout<<"The sum of values between the range 1 and 3 in the BST is "<<rangeSumBST(root, 1, 3)<<endl;
	return 0;
}

