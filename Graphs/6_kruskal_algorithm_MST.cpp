/* C++ program to implement kruskal algorithm for finding minimum cost spanning tree
Reference - https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
*/

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

vector<int> parent;

void initialise(int V){
	for(int i = 0; i<V; i++) parent.push_back(i);
}

int root(int u){
	while(parent[u] != u){
		parent[u] = parent[parent[u]];
		u = parent[u];
	}
	return u;
}

void union_set(int u, int v){
	int p_u = root(u);
	int p_v = root(v);
	parent[p_u] = parent[p_v];
}

int kruskal(vector<pair<int, pair<int, int>>> &edges){
	int u, v, min_cost = 0, cur_cost = 0;
	for(int i = 0; i<edges.size(); i++){
		u = edges[i].second.first;
		v = edges[i].second.second;
		cur_cost = edges[i].first;
		if(root(u) != root(v)){
			min_cost += cur_cost;
			union_set(u,v);
		}
	}
	return min_cost;
}

int main(){
	int E, V, u, v, weight;
	cout<<"Enter the number of edges and vertices "<<endl;
	cin>>E>>V;
	vector<pair<int, pair<int, int>>> edges;
	initialise(V);
	cout<<"Enter the edges "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v>>weight;
		edges.push_back(make_pair(weight, make_pair(u, v))); // storing (weight, (source_vertex, dest_vertex))
	}
	sort(edges.begin(), edges.end());
	int min_cost = kruskal(edges);
	cout<<"The cost of minimum spanning tree is "<<min_cost<<endl;
	return 0;
}
