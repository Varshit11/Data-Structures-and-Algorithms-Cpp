// C++ program to implement dijstra algorithm

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<pair<int, int>> adj_list[], int u, int v, int weight){
	adj_list[u].push_back(make_pair(v, weight));
	adj_list[v].push_back(make_pair(u, weight));
}

void dijkstra(vector<pair<int, int>> adj_list[], int source, int V){
	set<pair<int, int>> s;
	s.insert({0,source});
	vector<int> dist(V, INT_MAX);
	dist[source] = 0;
	while(!s.empty()){
		pair<int, int> temp = *(s.begin());
		int wt = temp.first;
		int u = temp.second;
		s.erase(s.begin());
		for(int i = 0; i<adj_list[u].size(); i++){
			int v = adj_list[u][i].first;
			int weight = adj_list[u][i].second;
			if(dist[v] > dist[u]+weight){
				if(dist[v] != INT_MAX)
					s.erase(s.find({dist[v], v}));
				dist[v] = dist[u] + weight;
				s.insert({dist[v], v});
			}
		}
	}
	
	for(int i = 0; i<V; i++)
		cout<<"Vertex: "<<i<<" distance: "<<dist[i]<<endl;
}

int main(){
	int V = 9;
	vector<pair<int, int>> adj_list[V];
	add_edge(adj_list, 0, 1, 4);
	add_edge(adj_list, 0, 7, 8);
	add_edge(adj_list, 1, 2, 8);
	add_edge(adj_list, 1, 7, 11);
	add_edge(adj_list, 2, 3, 7);
	add_edge(adj_list, 2, 8, 2);
	add_edge(adj_list, 2, 5, 4);
	add_edge(adj_list, 3, 4, 9);
	add_edge(adj_list, 3, 5, 14);
	add_edge(adj_list, 4, 5, 10);
	add_edge(adj_list, 5, 6, 2);
	add_edge(adj_list, 6, 7, 1);
	add_edge(adj_list, 6, 8, 6);
	add_edge(adj_list, 7, 8, 7);
	
	dijkstra(adj_list, 0, 9);
	return 0;
}

