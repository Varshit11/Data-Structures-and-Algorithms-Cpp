/* C++ program to solve play with chips problem
Problem Statement - https://leetcode.com/problems/play-with-chips/
*/

#include<bits/stdc++.h>
using namespace std;

int minCostToMoveChips(vector<int>& chips) {
    int ans[2] = {0,0};
    for(int i = 0; i<chips.size(); i++) ++ans[chips[i]%2];
    return min(ans[0], ans[1]);
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> chips = {2,2,2,3,3};
	cout<<minCostToMoveChips(chips)<<endl;
	return 0;
}
