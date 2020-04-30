/* C++ program to implement wiggle sort. We will implement this in O(n) time and O(1) space.
Problem Statement - https://leetcode.com/problems/wiggle-sort/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int* p, int* q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void wiggle_sort(vector<int> &nums){
	int i = 1;
	while(i<nums.size()){
		if(nums[i] < nums[i-1]) swap(&nums[i], &nums[i-1]);
		if(i+1 != nums.size() && nums[i] < nums[i+1]) swap(&nums[i], &nums[i+1]);
		i+=2;
	}
}

int main(){
	vector<int> nums = {3,5,2,1,4};
	wiggle_sort(nums);
	for(int i = 0; i<nums.size(); i++)
		cout<<nums[i]<<" ";
	return 0;
}

