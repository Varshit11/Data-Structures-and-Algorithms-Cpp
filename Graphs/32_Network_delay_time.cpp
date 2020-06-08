/* C++ program to solve Network Delay time problem
Problem Statement - https://leetcode.com/problems/network-delay-time/
*/

#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<pair<int, int>> adj_list[N+1];
    for(int i = 0; i<times.size(); i++){
        adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    set<pair<int, int>> s;
    s.insert({0, K});
    vector<int> dist(N+1, INT_MAX);
    dist[K] = 0;
    while(!s.empty()){
        pair<int, int> temp = *(s.begin());
        int wt = temp.first;
        int u = temp.second;
        s.erase(s.begin());
        for(int i = 0; i<adj_list[u].size(); i++){
            int v = adj_list[u][i].first;
            int weight = adj_list[u][i].second;
            if(dist[v]>dist[u]+weight){
                if(dist[v]!= INT_MAX)
                    s.erase(s.find({dist[v], v}));
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i<=N; i++){
        ans = max(ans, dist[i]);
    }
    return (ans == INT_MAX) ? -1 : ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
	int N = 4, K = 2;
	cout<<networkDelayTime(times, N, K)<<endl;
	return 0;
}

