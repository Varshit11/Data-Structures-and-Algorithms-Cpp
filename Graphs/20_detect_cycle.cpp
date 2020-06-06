// C++ program to find cycle in graph (undirected)

#include<iostream>
#include<vector>
using namespace std;

void initialise(vector<int> &parent){
	for(int i = 0; i<parent.size(); i++) parent[i] = i;
}

int find_root(vector<int> &parent, int i){
	while(parent[i] != i){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}

bool find_cycle(vector<vector<int>>& edges, vector<int> &parent){
	for(int i = 0; i<edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		int root_u = find_root(parent, u);
		int root_v = find_root(parent, v);
		if(root_u == root_v) return true;
		else parent[root_u] = root_v;
	}
}

int main(){
	int E = 3, V = 3;
	vector<int> parent(V);
	vector<vector<int>> edges;
	edges.push_back({0,1});
	edges.push_back({1,2});
	edges.push_back({0,2});
	initialise(parent);
	if(find_cycle(edges, parent)) cout<<"There exists cycle in graph"<<endl;
	else cout<<"There is no cycle in graph"<<endl;
	return 0;
}

