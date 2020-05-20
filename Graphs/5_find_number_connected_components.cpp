/* C++ program to find number of connected component in graph
Reference - https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u); // comment if directed graph
}

void dfs_util(vector<int> adj_list[], int u, vector<bool> &visited){
	visited[u] = true;
	for(int i = 0; i<adj_list[u].size(); i++) if(!visited[adj_list[u][i]]) dfs_util(adj_list, adj_list[u][i], visited);
}

int dfs(vector<int> adj_list[], int V){
	vector<bool> visited(V, false);
	int connected_comp = 0;
	for(int i = 0; i<V; i++){
		if(!visited[i]){
			dfs_util(adj_list, i, visited);
			connected_comp++;
		}
	}
	return connected_comp;
}

int main(){
	int E, V, u, v;
	cout<<"Enter the number of edges and vertices "<<endl;
	cin>>E>>V;
	vector<int> adj_list[V];
	cout<<"Enter the edges "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v;
		add_edge(adj_list, u, v);
	}
	int connected_comp = dfs(adj_list, V);
	cout<<"The number of connected components are "<<connected_comp<<endl;
	return 0;
}
