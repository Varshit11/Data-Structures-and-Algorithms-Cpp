/* C++ program to solve friend circles.
Problem Statement - https://leetcode.com/problems/friend-circles/
*/

#include<bits/stdc++.h>
using namespace std;

void initialise(vector<int> &parent){
        for(int i = 0; i<parent.size(); i++) parent[i] = i;
    }
    
int find_root(int i, vector<int> &parent){
    while(i!= parent[i]){
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}
    
void union_nodes(int u, int v, vector<int> &parent, int &count){
    int root_u = find_root(u, parent);
    int root_v = find_root(v, parent);
    if(root_u == root_v) return;
    parent[root_u] = root_v;
    --count;
}
    
int findCircleNum(vector<vector<int>>& M) {
    vector<int> parent(M.size());
    int count = M.size();
    initialise(parent);
    for(int i = 0; i<M.size(); i++){
        for(int j = i+1; j<M.size(); j++){
            if(M[i][j]) union_nodes(i, j, parent, count);
        }
    }
    return count;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration..
	vector<vector<int>> M = {{1,1,0}, {1,1,0}, {0, 0, 1}};
	cout<<"The total number of friend circles are "<<findCircleNum(M)<<endl;
	return 0;
}

