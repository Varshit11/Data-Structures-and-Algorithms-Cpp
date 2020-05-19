/* C++ program to perform DFS of an undirected and unweighted graph
Reference link - https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-1-dfs-of-unweighted-and-undirected/
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u); // comment this line if uni directional
}

void dfs_util(vector<int> adj_list[], int u, vector<bool>& visited){
	visited[u] = true;
	cout<<u<<" ";
	for(int i = 0; i<adj_list[u].size(); i++) if(!visited[adj_list[u][i]]) dfs_util(adj_list, adj_list[u][i], visited);
}

void dfs(vector<int> adj_list[], int V){
	vector<bool> visited(V, false);
	for(int i = 0; i<V; i++) if(!visited[i]) dfs_util(adj_list, i, visited);
}

int main(){
	int E, V, u, v;
	cout<<"Enter the number of edges and nodes"<<endl;
	cin>>E>>V;
	vector<int> adj_list[V];
	cout<<"Enter the edges "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v;
		add_edge(adj_list, u, v);
	}
	dfs(adj_list, V);
	return 0;
}
