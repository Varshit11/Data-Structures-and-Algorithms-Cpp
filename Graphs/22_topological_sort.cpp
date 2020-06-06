/* C++ program to implement topological sorting algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
}

void dfs(int u, vector<bool>& visited, stack<int> &s, vector<int> adj_list[]){
	visited[u] = true;
	for(int i = 0; i<adj_list[u].size(); i++){
		if(!visited[adj_list[u][i]]) dfs(adj_list[u][i], visited, s, adj_list);
	}
	s.push(u);	
}

void topological_sort(vector<int> adj_list[], int V){
	vector<bool> visited(V, false);
	stack<int> s;
	for(int i = 0; i<V; i++){
		if(!visited[i]) dfs(i, visited, s, adj_list);
	}
	
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main(){
	int V = 6;
	vector<int> adj_list[V];
	
	add_edge(adj_list, 5, 2);
	add_edge(adj_list, 5, 0);
	add_edge(adj_list, 4, 0);
	add_edge(adj_list, 4, 1);
	add_edge(adj_list, 2, 3);
	add_edge(adj_list, 3, 1);
	
	cout<<"The topological sort of this graph is "<<endl;
	topological_sort(adj_list, V);
	return 0;
}

