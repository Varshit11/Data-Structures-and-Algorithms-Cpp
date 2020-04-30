/* C++ program to wiggle sort, time complexity O(N*logN) and space O(1)
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
	sort(nums.begin(), nums.end());
	int i = 1, N;
	if(nums.size()%2 == 1) N = nums.size();
	else N = nums.size()-1;
	while(i<N){
		swap(&nums[i], &nums[i+1]);
		i+=2;
	}
}

int main(){
	vector<int> nums = {3,5,2,1,4, 6,10, 9, 8, 7};
	wiggle_sort(nums);
	for(int i = 0; i<nums.size(); i++)
		cout<<nums[i]<<" ";
	return 0;
}

