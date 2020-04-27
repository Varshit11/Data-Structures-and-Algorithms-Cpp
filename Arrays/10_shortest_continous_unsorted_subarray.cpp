/* C++ program to find Shortest Unsorted Continuous Subarray.
Problem statement - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int find_unsorted_subarray(vector<int> &nums){
	stack <int> s;
	int i, left = nums.size(), right = 0;
	for(i=0;i<nums.size();i++){
		while(!s.empty() && nums[s.top()]>nums[i]){
			left = min(left, s.top());
			s.pop();
		}
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	
	for(i=nums.size()-1; i>=0;i--){
		while(!s.empty() && nums[s.top()] < nums[i]){
			right = max(right, s.top());
			s.pop();
		}
		s.push(i);
	}
	if(right-left > 0)
		return right-left+1;
	else
		return 0;
}

int main(){
	// code passed all test cases on leetcode, one test case is used here for demonstration
	vector<int> nums = {2,6,4,8,10,9,15};
	cout<<"The shortest continous unsorted subarray is "<<find_unsorted_subarray(nums)<<endl;
	return 0;
}

