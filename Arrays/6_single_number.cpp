/* C++ program to solve Single number problem
Problem Statement - https://leetcode.com/problems/single-number/
*/
// we will use xor operator to solve this problem efficiently.
// Time = O(N) and space = O(1)

#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int v1;
    for(int i = 0; i<nums.size(); i++)
        v1^=nums[i];
    return v1;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {4,1,2,1,2};
	cout<<"The elements which occurs odd number of times is "<<singleNumber(nums)<<endl;
	return 0;
}

