/* C++ program to check if a graph is bipartite using BFS. 
Problem Statement - https://leetcode.com/problems/is-graph-bipartite/
*/

#include<bits/stdc++.h>
using namespace std;

bool bfs(int u, vector<int>& color, vector<bool>& visited, vector<vector<int>>& graph){
    queue<pair<int, int>> q;
    q.push({u, 0});
    visited[u] = true;
    color[u] = 0;
    while(!q.empty()){
        int cur_vertex = q.front().first;
        int cur_color = q.front().second;
        q.pop();
        cur_color = (!cur_color);
        for(int i = 0; i<graph[cur_vertex].size(); i++){
            int temp = graph[cur_vertex][i];
            if(!visited[temp]){
                q.push({temp, cur_color});
                color[temp] = cur_color;
                visited[temp] = true;
            }else{
                if(color[cur_vertex] == color[temp]) return false;
            }
        }
    }
    return true;
}
    
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> color(V, 0);
    vector<bool> visited(V, false);
    for(int i = 0; i<V; i++){
        if(!visited[i])
            if(!bfs(i, color, visited, graph)) return false;
    }
    return true;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> graph1 = {{1,3}, {0,2}, {1,3}, {0,2}};
	if(isBipartite(graph1)) cout<<"Graph1 is bipartite "<<endl;
	else cout<<"Graph1 is not bipartite"<<endl;
	
	vector<vector<int>> graph2 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
	if(isBipartite(graph2)) cout<<"Graph2 is bipartite"<<endl;
	else cout<<"Graph2 is not bipartite "<<endl;
	
	return 0;
}
