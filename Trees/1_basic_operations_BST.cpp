/* C++ program to implement basic operations in Binary search tree
1. Inserting a node in BST
2. Finding the minimum value in BST
3. Finding the maximum value in BST
4. Traversals - Preorder, postorder, inorder 
5. Search an element in the tree
6. Delete a node in BST 
Note - I am writing every function using recursion, we can do the same using while loop*/

#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

Node* insert(Node* root1, Node* temp){
	if(!root1)
		return temp;
	else if(root1->data > temp->data)
		root1->left = insert(root1->left, temp);
	else if(root1->data <= temp->data)
		root1->right = insert(root1->right, temp);
	
	return root1;
}

bool search_tree(Node* temp, int data){
	if(!temp)
		return false;
	else if(data < temp->data)
		return search_tree(temp->left, data);
	else if(data > temp->data)
		return search_tree(temp->right, data);
	else
		return true;
}

int find_min(Node* root1){
	if(!root1)
		return INT_MIN;
	else if(!root1->left)
		return root1->data;
	else
		return find_min(root1->left);
}

int find_max(Node* root1){
	if(!root1)
		return INT_MIN;
	else if(!root1->right)
		return root1->data;
	else
		return find_max(root1->right);
}

void inorder(Node* root1){
	if(!root1)
		return;
	inorder(root1->left);
	cout<<root1->data<<" ";
	inorder(root1->right);
}

void preorder(Node* root1){
	if(!root1)
		return;
	cout<<root1->data<<" ";
	preorder(root1->left);
	preorder(root1->right);
}

void postorder(Node* root1){
	if(!root1)
		return;
	postorder(root1->left);
	postorder(root1->right);
	cout<<root1->data<<" ";
}

Node* delete_node(Node* root1, int data){
	Node* temp;
	if(!root1)
		return root1;
	else if(root1->data > data)
		root1->left = delete_node(root1->left, data);
	else if(root1->data < data)
		root1->right = delete_node(root1->right, data);
	else if(root1->data == data && !root1->left && !root1->right){
		delete root1;
		return NULL;
	}
	else if(root1->data == data && !root1->left && root1->right){
		temp = root1;
		root1 = root1->right;
		delete temp;
		return root1;
	}
	else if(root1->data == data && !root1->right && root1->left){
		temp = root1;
		root1 = root1->left;
		delete temp;
		return root1;
	}
	else if(root1->data == data && root1->left && root1->right){
		// since root1 has 2 children, we will find inorder successor of root1
		int inord_succ = find_min(root1->right);
		root1->data = inord_succ;
		root1->right = delete_node(root1->right, inord_succ);
	}
	
	return root1;
}

int main(){
	Node* temp;
	temp = create_node(5);
	root = insert(root, temp);
	temp = create_node(3);
	root = insert(root, temp);
	temp = create_node(4);
	root = insert(root, temp);
	temp = create_node(2);
	root = insert(root, temp);
	
	if(!search_tree(root, 7)) // display element not found
		cout<<"Element not found"<<endl;
	else
		cout<<"Element found"<<endl;
		
	temp = create_node(8);
	root = insert(root, temp);
	temp = create_node(7);
	root = insert(root, temp);	
	temp = create_node(6);
	root = insert(root, temp);
	temp = create_node(9);
	root = insert(root, temp);

	if(!search_tree(root, 7)) // display Element found
		cout<<"Element not found"<<endl;
	else
		cout<<"Element found"<<endl;	
	
	cout<<"The maximum element is "<<find_max(root)<<endl; // display 9
	cout<<"The minimum element is "<<find_min(root)<<endl; // display 2
	
	cout<<"The inorder traversal of the tree is "<<endl;
	inorder(root);
	cout<<"\nThe postorder traversal of the tree is "<<endl;
	postorder(root);
	cout<<"\nThe preorder traversal of the tree is "<<endl;
	preorder(root);
	
	
	// now we will delete some elements..every time we delete we will do inorder
	// traversal to cross check.
	root = delete_node(root, 2); // 2 is the leaf node.
	cout<<"\nAfter deleting 2, the inorder traversal becomes"<<endl;
	inorder(root);
	
	root = delete_node(root, 7); // 7 has only left child but no right child
	cout<<"\nAfter deleting 7, the inorder traversal becomes"<<endl;
	inorder(root);
	
	root = delete_node(root, 5); // 5 is root node and has 2 children
	cout<<"\nAfter deleting 5, the inorder traversal becomes"<<endl;
	inorder(root);
	
	root = delete_node(root, 6); // now 6 becomes root, again it has 2 children
	cout<<"\nAfter deleting 6, the inorder traversal becomes"<<endl;
	inorder(root);
	return 0;
}

