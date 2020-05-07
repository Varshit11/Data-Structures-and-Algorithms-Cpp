/* C++ program to solve Cousins in Binary tree problem. 
Problem Statement - https://leetcode.com/problems/cousins-in-binary-tree/
I will solve this using both BFS and DFS
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
};

Node* create_node(int data){
	Node* temp = new Node;
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool is_cousins_BFS(Node* root, int x, int y) {
    queue <Node*> q;
    Node* temp;
    q.push(root);
    while(!q.empty()){
        int count = 2;
        int d = q.size();
        while(d-- > 0){
            temp = q.front();
            if(temp->left && temp->right)
                if((temp->left->val == x && temp->right->val == y) || (temp->left->val == y && temp->right->val == x)) return false;
            if(temp->left){
                if(temp->left->val == x || temp->left->val == y) count--;
                q.push(temp->left);
            }
            if(temp->right){
                if(temp->right->val == x || temp->right->val == y) count--;
                q.push(temp->right);
            }
            q.pop();
        }
        if(count == 0) return true;
        else if(count == 1) return false;
    }
    return false;
}

Node* dfs(Node* root, int f, int level, int &depth){
	if(!root) return NULL;
	if((root->left && root->left->val == f) || (root->right && root->right->val == f)){
		depth = level;
		return root;
	}
	Node* left = dfs(root->left, f, level+1, depth);
	if(left) return left;
	Node* right = dfs(root->right, f, level+1, depth);
	if(right) return right;
	return NULL;
}

bool is_cousins_DFS(Node* root, int x, int y){
	int d1 = INT_MIN, d2 = INT_MIN;
	Node* temp1 = dfs(root, x, 0, d1);
	Node* temp2 = dfs(root, y, 0, d2);
	if(temp1 == temp2 || d1 != d2) return false;
	return true;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	Node* root = create_node(1);
	root->left = create_node(2);
	root->left->right = create_node(4);
	root->right = create_node(3);
	root->right->right = create_node(5);
	if(is_cousins_BFS(root, 5,4)) cout<<"Using BFS, The nodes with values 5 and 4 are cousins "<<endl;
	else cout<<"Using BFS, The nodes with values 5 and 4 are cousins "<<endl;
	if(is_cousins_DFS(root, 5,4)) cout<<"Using DFS, The nodes with values 5 and 4 are cousins "<<endl;
	else cout<<"Using DFS, The nodes with values 5 and 4 are cousins "<<endl;
	return 0;
}

