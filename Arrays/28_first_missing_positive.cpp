/* C++ program to find the first missing positive
Problem Statement - https://leetcode.com/problems/first-missing-positive/
*/

#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int i, flag = 0;
    for(i=0;i<nums.size(); i++){
        if(nums[i] == 1) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) return 1;
    for(i=0;i<nums.size();i++)
        if(nums[i] <= 0 || nums[i] > nums.size()) nums[i] = 1;
    for(i=0;i<nums.size(); i++){
        int val = abs(nums[i]);
        if(val == nums.size()) nums[0] = -abs(nums[0]);
        else nums[val] = -1*abs(nums[val]);
    }
    for(i=1;i<nums.size();i++){
        if(nums[i] > 0) return i;
    }
    if(nums[0] > 0)
        return nums.size();
    return nums.size()+1;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {1,0,2};
	cout<<"The first missing positive element is "<<firstMissingPositive(nums)<<endl;
	return 0;
}

