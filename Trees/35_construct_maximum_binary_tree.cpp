/* C++ program to implement maximum binary tree problem 
Problem link - https://leetcode.com/problems/maximum-binary-tree/
*/

#include<iostream>
#include<vector>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
		Node(int data): val(data), left(NULL), right(NULL) {}
};

int search_max(vector<int> &nums, int lower, int higher){
    int max_index = lower;
    for(int i = lower+1; i<=higher; i++){
        if(nums[max_index] < nums[i])
            max_index = i;
    }
    return max_index;
}

Node* construct(vector<int>& nums, int lower, int higher){
    if(lower > higher)
        return NULL;
    int i = search_max(nums, lower, higher);
    Node* root = new Node(nums[i]);
    root->left = construct(nums, lower, i-1);
    root->right = construct(nums, i+1, higher);
    return root;
}

Node* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size()-1);
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){
	int N, i, d;
	cout<<"Enter the number of elements in tree to be constructed"<<endl;
	cin>>N;
	vector<int> nums;
	cout<<"Enter the elements "<<endl;
	for(i=0;i<N;i++){
		cin>>d;
		nums.push_back(d);
	}
	Node* root = constructMaximumBinaryTree(nums);
	cout<<"The inorder traversal of the tree constructed is "<<endl;
	inorder(root);
	return 0;
}

