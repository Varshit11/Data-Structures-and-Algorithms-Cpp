/* C++ program to find bridges in a graph. To know more about bridges refer Geeks for geeks */

#include<iostream>
#include<vector>
using namespace std;
#define NIL -1

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void DFS_bridges(vector<int>& parent, vector<bool>& visited, vector<int>& disc, vector<int>& low,
				int u, vector<int> adj_list[])
{
	static int time = 0;
	int child_nodes = 0;
	visited[u] = true;
	low[u] = disc[u] = ++time;
	for(int i = 0; i<adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(!visited[v]){
			child_nodes++;
			parent[v] = u;
			
			DFS_bridges(parent, visited, disc, low, v, adj_list);
			
			low[u] = min(low[u], low[v]);
			
			if(low[v] > disc[u])
				cout<<"The edge connecting "<<u<<" and "<<v<<" is bridge "<<endl;
		}
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}					
}

void bridges(vector<int> adj_list[], int V){
	vector<int> disc(V);
	vector<int> low(V);
	vector<int> parent(V, NIL);
	vector<bool> visited(V, false);
	
	for(int i = 0; i<V; i++){
		if(!visited[i])
			DFS_bridges(parent, visited, disc, low, i, adj_list);
	} 
}

int main(){
	int V = 6;
	vector<int> adj_list[V];
	
	add_edge(adj_list, 0, 5);
	add_edge(adj_list, 0, 1);
	add_edge(adj_list, 1, 2);
	add_edge(adj_list, 1, 3);
	add_edge(adj_list, 2, 3);
	add_edge(adj_list, 2, 4);
	add_edge(adj_list, 3, 4);
	
	bridges(adj_list, V);
	return 0;
}

