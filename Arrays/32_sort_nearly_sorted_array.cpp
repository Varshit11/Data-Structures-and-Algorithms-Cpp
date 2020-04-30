/* C++ program to sort nealy sorted array
Problem Statement - https://www.geeksforgeeks.org/nearly-sorted-algorithm/
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void sort_nearly_sorted(vector<int> &nums, int k){
	priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin()+k);
	int i, j = 0;
	for(i = k; i<= nums.size()-1; i++){
		if(nums[i] <= pq.top()){
			nums[j++] = nums[i];
		}
		else{
			nums[j++] = pq.top();
			pq.pop();
			pq.push(nums[i]);
		}
	}
	
	while(!pq.empty()){
		nums[j++] = pq.top();
		pq.pop();
	}
}

int main(){
	vector<int> nums = {10, 9, 8, 7, 4, 70, 60, 50};
	sort_nearly_sorted(nums, 4); // k is 4 here
	for(int i = 0;i<nums.size(); i++)
		cout<<nums[i]<<" ";
	return 0;
}

