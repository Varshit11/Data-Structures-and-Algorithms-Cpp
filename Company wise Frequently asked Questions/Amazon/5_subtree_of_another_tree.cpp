/* C++ program to solve Subtree of Another Tree problem
Problem Statement - https://leetcode.com/problems/subtree-of-another-tree/
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode{
	public:
		int val;
		TreeNode* left;
		TreeNode* right;
};

vector<TreeNode*> temp;

TreeNode* new_node(int data){
	TreeNode* t = new TreeNode;
	t->val = data;
	t->left = NULL;
	t->right = NULL;
	return t;
}

void find(TreeNode* s, TreeNode* t){
    if(!s) return;
    if(t->val == s->val) temp.push_back(s);
    find(s->left, t);
    find(s->right, t);
}
    
bool compare(TreeNode* s, TreeNode* t){
    if(!s && !t) return true;
    else if(!s) return false;
    else if(!t) return false;
    else return (s->val == t->val && compare(s->left, t->left) && compare(s->right, t->right));
}
    
bool isSubtree(TreeNode* s, TreeNode* t) {
    find(s, t);
    for(int i = 0; i<temp.size(); i++) if(compare(temp[i], t)) return true;
    return false;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	TreeNode* root = new_node(1);
	root->left = new_node(1);
	
	TreeNode* sub_root = new_node(1);
	
	if(isSubtree(root, sub_root)) cout<<"The second tree is sub tree of first tree"<<endl;
	else cout<<"The second tree is not a sub tree of first tree "<<endl;
	return 0;
}

