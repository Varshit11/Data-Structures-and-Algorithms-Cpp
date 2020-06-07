/* C++ program to solve Redundant connection problem
Problem Statement - https://leetcode.com/problems/redundant-connection/
*/

#include<bits/stdc++.h>
using namespace std;

int find_root(int u, vector<int> &parent){
        while(u!=parent[u]){
            parent[u] = parent[parent[u]];
            u = parent[u];
        }
        return u;
    }
  
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    vector<int> ans(2); // stores answer 
    int V = edges.size(); // number of vertices
    vector<int> parent(V+1);
    for(int i = 1; i<parent.size(); i++) parent[i] = i;
           
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i][0], v = edges[i][1];
        int root_u = find_root(u, parent), root_v = find_root(v, parent);
        if(root_u == root_v){
            ans[0] = u;
            ans[1] = v;
        }
        else{
            parent[root_u] = root_v; 
        }
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> edges = {{1,2}, {2,3}, {3,4}, {1,4},{1,5}};
	vector<int> ans = findRedundantConnection(edges);
	cout<<"After removing edge connecting vertices "<<ans[0]<<" and "<<ans[1]<<" we get a tree"<<endl;
	return 0;
}

