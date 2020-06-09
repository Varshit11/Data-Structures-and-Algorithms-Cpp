/* C++ program to solve Minimum Subsequence in Non-Increasing Order problem
Problem Statement - https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
*/

#include<iostream>
#include<vector>
#include<algorithm> // for accumulate and sort functions
using namespace std;

vector<int> minSubsequence(vector<int>& nums) {
    if(nums.size() == 1) return {nums[0]};
    int sum = accumulate(nums.begin(), nums.end(), 0), temp = 0;
    vector<int> ans;
    sort(nums.begin(), nums.end());

    for(int i = nums.size()-1; i>=0; i--){
        temp += nums[i];
        ans.push_back(nums[i]);
        if(temp > sum-temp) return ans;
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {4,4,7,6,7};
	vector<int> ans = minSubsequence(nums);
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	return 0;
}

