// C++ program to implement floyd warshall algorithm

#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define V 4

void print_all_pair_dist(vector<vector<int>>& all_pair){
	for(int i = 0; i<V; i++){
		for(int j = 0; j<V; j++){
			if(all_pair[i][j] == INF) cout<<"INF\t";
			else cout<<all_pair[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void floyd_warshall(vector<vector<int>>& adj_matrix){
	vector<vector<int>> all_pair(adj_matrix); // copying elements of adj_matrix
	for(int k = 0; k<V; k++){
		for(int i = 0; i<V; i++){
			for(int j = 0; j<V; j++){
				if(all_pair[i][k] != INF && all_pair[k][j] != INF && 
				all_pair[i][j] > all_pair[i][k] + all_pair[k][j]) 
					all_pair[i][j] = all_pair[i][k] + all_pair[k][j];
			}
		}
	}
	print_all_pair_dist(all_pair);
}

int main(){
	vector<vector<int>> adj_matrix = {{0, 5, INF, 10},{INF, 0, 3, INF},{INF, INF, 0, 1},
	{INF, INF, INF, 0}};
	floyd_warshall(adj_matrix);
	return 0;
}

