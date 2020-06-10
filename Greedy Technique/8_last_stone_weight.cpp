/* C++ program to solve Last stone weight problem
Problem Statement - https://leetcode.com/problems/last-stone-weight/
*/

#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    if(stones.size() == 1) return stones[0];
    priority_queue<int> pq;
    for(auto x: stones) pq.push(x);
        
    while(pq.size() > 1){
        int y = pq.top();
        pq.pop();
        int x = pq.top();
        pq.pop();
        if(y-x != 0) pq.push(y-x);
    }
    return pq.empty() ? 0 : pq.top();
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here demonstration
	vector<int> stones = {2,7,4,1,8,1};
	cout<<lastStoneWeight(stones)<<endl;
	return 0;
}

