/* C++ program to solve Possible Bipartition problem
Problem Statement - https://leetcode.com/problems/possible-bipartition/
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
    adj_list[u-1].push_back(v-1);
    adj_list[v-1].push_back(u-1);
}
    
bool dfs_util(vector<int> adj_list[], int u, vector<int> &visited, int col){
    visited[u] = col;
    for(int i = 0; i<adj_list[u].size(); i++){
        if(visited[adj_list[u][i]] == 0) {
            if(dfs_util(adj_list, adj_list[u][i], visited, -col)) return true;
        }
        else if(visited[adj_list[u][i]] == visited[u]) return true;
    }
    return false;
}
    
bool dfs(vector<int> adj_list[], int N){
    vector<int> visited(N, 0);
    for(int i = 0; i<N; i++){
        if(visited[i] == 0) if(dfs_util(adj_list, i, visited, 1)) return true;
    }
    return false;
}
    
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<int> adj_list[N];
    for(int i = 0; i<dislikes.size(); i++) add_edge(adj_list, dislikes[i][0], dislikes[i][1]);
    if(dfs(adj_list, N)) return false;
    return true;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int N = 5;
	vector<vector<int>> dislikes = {{1,2}, {2,3}, {3,4}, {4,5}, {1,5}};
	if(possibleBipartition(N, dislikes)) cout<<"It is possible to split everyone into two groups"<<endl;
	else cout<<"It is not possible to split everyone into two groups"<<endl;
	return 0;
}

