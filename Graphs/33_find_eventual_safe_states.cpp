/* C++ program to Find Eventual Safe States
Problem Statement - https://leetcode.com/problems/find-eventual-safe-states/
*/

#include<bits/stdc++.h>
using namespace std;

// below code is brute force, detecting cycle for every edge (Give time limit exceeded)
//bool dfs(int u, vector<vector<int>> &graph, vector<bool> &visited, vector<bool> &rec_stack){
//        if(!visited[u]){
//            visited[u] = true;
//            rec_stack[u] = true;
//            for(int i = 0; i<graph[u].size(); i++){
//                int temp = graph[u][i];
//                if(!visited[temp] && dfs(temp, graph, visited, rec_stack))
//                    return true;
//                else if(rec_stack[temp]) return true;
//            }
//        }
//        rec_stack[u] = false;
//        return false;
//    }
//    
//    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
//        vector<int> ans;
//        for(int i = 0; i<graph.size(); i++){
//            vector<bool> rec_stack(graph.size(), false);
//            vector<bool> visited(graph.size(), false);
//            if(!dfs(i, graph, visited, rec_stack)) ans.push_back(i);
//        }
//        return ans;
//    }

// this is efficient simple DFS solution.
bool dfs(int u, vector<vector<int>>& graph, vector<int> &color){
    if(color[u]) return color[u] == 1;
    color[u] = 2;
    for(int i = 0; i<graph[u].size(); i++){
        if(!dfs(graph[u][i], graph, color)) return false;
    }
    color[u] = 1;
    return true;
}
    
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int> color(graph.size(), 0);
    vector<int> ans;
    for(int i = 0; i<graph.size(); i++){
        if(dfs(i, graph, color)) ans.push_back(i);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> graph = {{1,2},{2,3}, {5}, {0}, {5}, {}, {}};
	vector<int> ans = eventualSafeNodes(graph);
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

