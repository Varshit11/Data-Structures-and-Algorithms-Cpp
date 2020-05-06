/* C++ program to solve maximum subarray problem 
Problem Statement - https://leetcode.com/problems/maximum-subarray/
*/

#include<iostream>
#include<vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max_value = nums[0], temp = nums[0];
    for(int i = 1; i<nums.size(); i++) {
        temp = max(nums[i], nums[i]+temp);
        max_value = max(temp, max_value);
    }
    return max_value;
}

int main(){
	vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
	cout<<"The maximum subarray in this array is "<<maxSubArray(nums)<<endl;
	return 0;
}

