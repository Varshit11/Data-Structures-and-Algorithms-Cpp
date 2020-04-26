/* C++ program to merge k sorted arrays 
Problem statement - https://www.geeksforgeeks.org/merge-k-sorted-arrays-set-2-different-sized-arrays/
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
	public:
		int data;
		int vec_idx; // vector index in vector of vectors
		int data_idx; // data index in vector
		Node(int x, int y, int z):data(x), vec_idx(y), data_idx(z) {}
};

struct Comparator{
	bool operator()(Node const& p1, Node const& p2){
		return p1.data > p2.data; // for min heap..
	}
};

void merge_k_arrays(vector<vector<int>>& nums, int K){
	int i;
	priority_queue <Node, vector<Node>, Comparator> p;
	for(i=0;i<K;i++){
		p.push(Node(nums[i][0], i, 0));
	}
	while(p.top().data != INT_MAX){
		Node temp = p.top();
		p.pop();
		cout<<temp.data<<" ";
		if(temp.data_idx == nums[temp.vec_idx].size()-1)
			temp.data = INT_MAX;
		else{
			temp.data = nums[temp.vec_idx][temp.data_idx+1];
			temp.data_idx++;
		}
		p.push(temp);
	}
}

int main(){
	vector <vector<int>> nums = {{1,3}, {2,4,6}, {0,9,10,11}};
	cout<<"After sorting K arrays the final array is "<<endl;
	merge_k_arrays(nums, 3); // k = 3 as there are 3 arrays
	return 0;
}

