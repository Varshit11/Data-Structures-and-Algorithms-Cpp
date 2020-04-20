/* C++ program to construct the binary tree from inorder and postorder 
traversals.*/

#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* root = NULL;
unordered_map <int , int> umap;

Node* create_node(int data){
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int find_index(int data){ // to make search index O(1) hashing is used
	return umap[data]; // on the assumption that data exists in umap;
}

Node* create_tree(int start_in, int end_in, int start_post, int end_post, int* inor, int* post){
	if(start_in>end_in)
		return NULL;
	if(start_in == end_in)
		return create_node(inor[start_in]);
	
	Node* temp_root = create_node(post[end_post]);
	int idx = find_index(post[end_post]);
	
	temp_root->left = create_tree(start_in, idx-1, start_post, idx-1, inor, post);
	temp_root->right = create_tree(idx+1, end_in, idx, end_post-1, inor, post);
	return temp_root;
}

void inorder(Node* root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main(){
	int N, i;
	cout<<"Enter the number of elements in the tree "<<endl;
	cin>>N;
	int* post = new int[N];
	int* inor = new int[N];
	cout<<"Enter the inorder traversal "<<endl;
	for(i=0; i<N; i++){
		cin>>inor[i];
		umap[inor[i]] = i;
	}
	cout<<"Enter the postorder traversal "<<endl;
	for(i=0; i<N; i++){
		cin>>post[i];
	}
	root = create_tree(0, N-1, 0, N-1, inor, post);
	cout<<"The inorder traversal of the tree created is "<<endl;
	inorder(root);
	return 0;
}

