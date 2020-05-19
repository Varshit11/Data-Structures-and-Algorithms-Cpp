/* C++ program to find breadth first search of given undirected and unweighted graph
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj_list[], int u, int v){
	adj_list[u].push_back(v);
	adj_list[v].push_back(u);
}

void bfs_util(vector<int> adj_list[], int start, vector<bool>& visited, vector<int>& level){
	queue<int> q;
	q.push(start);
	visited[start] = true;
	level[start] = 0;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		cout<<cur<<" ";
		for(int i = 0; i<adj_list[cur].size(); i++){
			if(!visited[adj_list[cur][i]]){
				visited[adj_list[cur][i]] = true;
				level[adj_list[cur][i]] = level[cur] + 1;
				q.push(adj_list[cur][i]);
			}
		}
	}
}

void bfs(vector<int> adj_list[], int V){
	vector<int> level(V, 0);
	vector<bool> visited(V, false);
	for(int i = 0; i<V; i++)
		if(!visited[i]) bfs_util(adj_list, i, visited, level);
	cout<<"The levels of each node are "<<endl;
	for(int i = 0; i<V; i++) cout<<"Node "<<i<<" level = "<<level[i]<<endl;
}

int main(){
	int E, V, u, v;
	cout<<"Enter the number of edges and vertices in graph"<<endl;
	cin>>E>>V;
	vector<int> adj_list[V];
	cout<<"Enter the edges of the graph "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v;
		add_edge(adj_list, u, v);
	}
	bfs(adj_list, V);
	return 0;
}
