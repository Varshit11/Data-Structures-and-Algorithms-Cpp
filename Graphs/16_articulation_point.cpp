/* C++ program to find the articulation points in the given graph */

#include<bits/stdc++.h>
using namespace std;
#define NIL -1

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void APUtil(vector<bool>& visited, vector<int>& parent, vector<int>& low, vector<int>& disc, 
			vector<bool>& ap_point, int u, vector<int> adj_list[])
{
	static int time = 0;
	visited[u] = true;
	int child_nodes = 0;
	disc[u] = low[u] = ++time;
	for(int i = 0; i<adj_list[u].size(); i++){
		int v = adj_list[u][i];
		if(!visited[v]){
			child_nodes++;
			parent[v] = u;
			
			APUtil(visited, parent, low, disc, ap_point, v, adj_list);
			
			low[u] = min(low[u], low[v]);
			
			if(parent[u] == NIL && child_nodes > 1)
				ap_point[u] = true;
			if(parent[u] != NIL && low[v]>=disc[u])
				ap_point[u] = true;

		}
		else if(v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

void AP(int V, vector<int> adj_list[]){
	vector<int> disc(V);
	vector<int> low(V);
	vector<int> parent(V, NIL);
	vector<bool> ap_point(V, false);
	vector<bool> visited(V, false);
	
	for(int i = 0; i<V; i++){
		if(!visited[i])
			APUtil(visited, parent, low, disc, ap_point, i, adj_list);
	}
	
	for(int i = 0; i<V; i++){
		if(ap_point[i])
			cout<<i<<" is the articulation point "<<endl;
	}
}

int main(){
	int V = 5;
	vector<int> adj_list[V];
	add_edge(adj_list, 1, 0);
	add_edge(adj_list, 0, 2);
	add_edge(adj_list, 2, 1);
	add_edge(adj_list, 0, 3);
	add_edge(adj_list, 3, 4);
	AP(V, adj_list);
	return 0;
}

