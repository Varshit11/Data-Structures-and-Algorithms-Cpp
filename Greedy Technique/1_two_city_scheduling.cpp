/* C++ program to solve two city scheduling problem
Problem Statement - https://leetcode.com/problems/two-city-scheduling/
*/

#include<bits/stdc++.h>
using namespace std;

bool sort_cond( const vector<int>& v1, const vector<int>& v2 ) { 
    return v1[0]-v1[1] < v2[0]-v2[1]; 
} 
    
int twoCitySchedCost(vector<vector<int>>& costs) {
    int N = costs.size(), min_cost = 0;
    sort(costs.begin(), costs.end(), sort_cond);
    for(int i = 0; i<N; i++){
        if(i<N/2) min_cost+= costs[i][0];
        else min_cost+= costs[i][1];
    }
    return min_cost;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration.
	vector<vector<int>> costs = {{10,20}, {30, 200}, {400, 50}, {30, 20}};
	cout<<"The minimum cost is "<<twoCitySchedCost(costs)<<endl;
	return 0;
}

