/* C++ program to check if a given graph is bipartite or not */

#include<iostream>
#include<vector>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

int color_vertex(int u, int prev_color, vector<int>& color){
	int cur_color;
	if(prev_color == 0){
		cur_color = 1;
		color[u] = cur_color;
	}else{
		cur_color = 0;
		color[u] = cur_color;
	}
	return cur_color;
}

bool check_color(int u, int v, vector<int> &color){
	return color[u] == color[v];
}

bool dfs(int u, int prev_color, vector<bool> &visited, vector<int> adj_list[], vector<int> &color){
	visited[u] = true;
	int cur_color = color_vertex(u, prev_color, color);
	for(int i = 0; i<adj_list[u].size(); i++){
		if(!visited[adj_list[u][i]]){
			if(!dfs(adj_list[u][i], cur_color, visited, adj_list, color)) return false;
		}
		else{
			if(check_color(u, adj_list[u][i], color)) return false;
		}
	}
	return true;
}

bool bipartite(vector<int> adj_list[], int V){
	vector<bool> visited(V, false);
	vector<int> color(V, 0);
	for(int i = 0; i<V; i++){
		if(!visited[i]) {
			if(!dfs(i, 0, visited, adj_list, color)) return false;
		}
	}
	return true; 
}

int main(){
	int V = 6;
	vector<int> adj_list[V];
	
	add_edge(adj_list, 0, 1);
	add_edge(adj_list, 1, 2);
	add_edge(adj_list, 2, 3);
	add_edge(adj_list, 3, 4);
	add_edge(adj_list, 4, 5);
	add_edge(adj_list, 5, 0);
	
	if(bipartite(adj_list, V)) cout<<"The graph is bipartite "<<endl;
	else cout<<"The graph is not bipartite "<<endl;
	
	return 0;
}

