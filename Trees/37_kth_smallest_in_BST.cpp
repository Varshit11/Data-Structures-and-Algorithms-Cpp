/* C++ program to find Kth Smallest Element in a BST
Problem Statement - https://leetcode.com/problems/kth-smallest-element-in-a-bst/
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode(): val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

void modified_inorder(TreeNode* root, int k, int &count, int &ans){
    if(!root) return;
    modified_inorder(root->left, k, count, ans);
    count++;
    if(count == k) {
        ans = root->val;
        return;
    }
    modified_inorder(root->right, k, count, ans);
}
    
int kthSmallest(TreeNode* root, int k) {
    int count = 0, ans = 0;
    modified_inorder(root, k, count, ans);
    return ans;
}

int kthSmallest_using_stack(TreeNode* root, int k){
	stack<TreeNode*> s;
	s.push(root);
	root = root->left;
	while(!s.empty()){
		while(root){
			s.push(root);
			root = root->left;
		}
		root = s.top();
		s.pop();
		if(!(--k)) return root->val;
		root = root->right;
	}
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration.
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	
	cout<<"The 2nd smallest element in this BST is "<<kthSmallest(root, 2)<<endl;
	cout<<"Using explicit stack, the 2nd smallest element in the BST is "<<kthSmallest_using_stack(root, 2);
	return 0;	
}

