/* C++ program to implement leaf-similar trees problem. 2 trees are called
leaf similar if the leaf nodes of both the trees are same and follows the same 
order */

#include<iostream>
#include<vector>
using namespace std;

class Node{
	public:
		int val;
		Node* left;
		Node* right;
};

Node* root1 = NULL;
Node* root2 = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->val = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}



void find_nodes(Node* root, vector<int> &v){
    if(!root)
        return;
    if(!root->left && !root->right)
        v.push_back(root->val);
    find_nodes(root->left, v);
    find_nodes(root->right, v);
}

bool leafSimilar(Node* root1, Node* root2) {
    vector<int> v1;
    vector<int> v2;
    find_nodes(root1, v1);
    find_nodes(root2, v2);
    return v1 == v2;
}

int main(){
	root1 = create_node(3);
	root1->left = create_node(8);
	root1->right = create_node(4);
	root1->left->left = create_node(7);
	root1->right->left = create_node(5);
	root1->right->right = create_node(6);
	
	root2 = create_node(3);
	root2->left = create_node(7);
	root2->right = create_node(4);
	root2->right->left = create_node(5);
	root2->right->right = create_node(6);
	
	if(leafSimilar(root1, root2))
		cout<<"The leaf nodes of both the trees are same"<<endl;
	else
		cout<<"The leaf nodes of both the trees are not same"<<endl;
	return 0;
}

