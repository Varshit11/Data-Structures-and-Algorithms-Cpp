/* C++ program to find K Closest Points to Origin
Problem Statement - https://leetcode.com/problems/k-closest-points-to-origin/
*/

#include<bits/stdc++.h>
using namespace std;

struct Compare{ 
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) 
    { 
        return p1.first < p2.first; 
    } 
}; 
    
int find_square(vector<int> &v){
    return v[0]*v[0] + v[1]*v[1];
}
    
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<vector<int>> ans;
    if(K>points.size()) return ans;
    for(int i = 0; i<K; i++) pq.push(make_pair(find_square(points[i]), i));
        
    for(int i = K; i<points.size(); i++){
        int sq = find_square(points[i]);
        if(sq<pq.top().first){
            pq.pop();
            pq.push(make_pair(sq, i));
        }
    }
    for(int i = 0; i<K; i++){
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> points = {{3,3},{5,-1},{-2,4}};
	int K = 2;
	vector<vector<int>> ans = kClosest(points, K);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

