/* C++ program to solve 0-1 BFS (minimum distance from source vertex in weighted undirected graph with weights 0 or 1)
Reference - https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/

#include<bits/stdc++.h>
using namespace std;

void add_edge(vector<pair<int, int>> adj_list[], int u, int v, int weight){
	adj_list[u].push_back(make_pair(v, weight));
	adj_list[v].push_back(make_pair(u, weight));
}

void bfs(vector<pair<int, int>> adj_list[], int source, int V){
	vector<int> dist(V, INT_MAX);
	dist[source] = 0;
	deque<int> dq;
	dq.push_back(source);
	while(!dq.empty()){
		int cur = dq.front();
		dq.pop_front();
		for(int i = 0; i<adj_list[cur].size(); i++){
			if(dist[adj_list[cur][i].first] > dist[cur] + adj_list[cur][i].second){
				dist[adj_list[cur][i].first] = dist[cur] + adj_list[cur][i].second;
				if(adj_list[cur][i].second) dq.push_back(adj_list[cur][i].first); // if edge weight 1 then push back in the deque
				else dq.push_front(adj_list[cur][i].first); // if edge weight 0 then push front in the deque
			}
		}
	}
	for(int i = 0; i<dist.size(); i++) cout<<"Distance from 0 to "<<i<<" vertex is "<<dist[i]<<endl;
}

int main(){
	int E,V, u, v, weight;
	cout<<"Enter the number of edges and vertices "<<endl;
	cin>>E>>V;
	vector<pair<int, int>> adj_list[V];
	cout<<"Enter the edges with weights "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v>>weight;
		add_edge(adj_list, u, v, weight);
	}
	bfs(adj_list, 0, V);
	return 0;
}
