/* C++ program to populate next right pointers in each node.
Problem link - https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;
		Node(int data): val(data), left(NULL), right(NULL), next(NULL){}
};

Node* root = NULL;

Node* connect(Node* root) {
    if(!root)
        return NULL;
    queue <Node*> q;
    Node* temp;
    q.push(root);
    while(!q.empty()){
        int d = q.size();
        while(d--){
            temp = q.front();
            q.pop();
            if(d == 0)
                temp->next = NULL;
            else
                temp->next = q.front();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    return root;
}


int main(){
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	root = connect(root);
	// this code is tested on leetcode and passed on all test cases.
	return 0;
}

