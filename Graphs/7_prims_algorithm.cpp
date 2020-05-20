/* C++ program to implement Prim's algorithm
Reference - https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

void add_edge(vector<pair<int, int>> adj_list[], int u, int v, int weight){
	adj_list[u].push_back(make_pair(weight, v));
	adj_list[v].push_back(make_pair(weight, u));
}

int prims(vector<pair<int, int>> adj_list[], int source, int V){
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
	vector<bool> visited(V, false);
	pq.push(make_pair(0, source));
	int min_cost = 0;
	while(!pq.empty()){
		pair<int, int> temp = pq.top();
		pq.pop();
		int v = temp.second;
		if(visited[v]) continue;
		min_cost += temp.first;
		visited[v] = true;
		for(int i = 0; i<adj_list[v].size(); i++) if(!visited[adj_list[v][i].second]) pq.push(adj_list[v][i]);
	}
	return min_cost;
}

int main(){
	int E, V, u, v, weight;
	cout<<"Enter the number of edges and vertices "<<endl;
	cin>>E>>V;
	vector<pair<int, int>> adj_list[V];
	cout<<"Enter the edges with weights "<<endl;
	for(int i = 0; i<E; i++){
		cin>>u>>v>>weight;
		add_edge(adj_list, u, v, weight);
	}
	int min_cost = prims(adj_list, 0, V);
	cout<<"The minimum spanning tree cost using prims algorithm is "<<min_cost<<endl;
	return 0; 
}

