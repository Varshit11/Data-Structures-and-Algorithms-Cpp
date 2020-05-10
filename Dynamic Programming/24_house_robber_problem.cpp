/* C++ program to solve house robber problem
Problem Statement - https://leetcode.com/problems/house-robber/
*/

#include<iostream>
#include<vector>
using namespace std;

int rob_recursion(vector<int>& nums, int N){
	if(N == 0) return 0;
	else if(N == 1) return nums[0];
	return max(nums[N-1] + rob_recursion(nums, N-2), rob_recursion(nums, N-1));
}

int rob(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    else if(nums.size() == 1) return nums[0];
    int m[nums.size()+1];
    m[0] = 0;
    m[1] = nums[0];
    for(int i = 2; i<=nums.size(); i++) m[i] = max(nums[i-1]+m[i-2], m[i-1]);
    return m[nums.size()];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {2,1,1,2};
	cout<<"Using recursion answer is "<<rob_recursion(nums, 4)<<endl;
	cout<<"Using bottom up DP answer is "<<rob(nums);
	return 0;
}
