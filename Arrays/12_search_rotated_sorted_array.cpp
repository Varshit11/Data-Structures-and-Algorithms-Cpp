/* C++ program to Search in Rotated Sorted Array. Given an sorted but rotated 
array, and a sum value, you have to find if there are any 2 values in the array 
whose addition equals to the sum value given. */

#include<iostream>
#include<vector>
using namespace std;

bool search_sum(vector<int> &nums, int sum){
	int left, right, i, temp;
	for(i=0;i<nums.size()-1;i++){
		if(nums[i+1] < nums[i]){
			right = i;
			left = i+1;
			break;
		}
	}
	while(left!=right){
		temp = nums[left] + nums[right];
		if(temp == sum)
			return true;
		else if(temp > sum){
			if(right == 0)
				right = nums.size()-1;
			else
				right = right-1;
		}else{
			left = (left+1)%(nums.size());
		}
	}
	return false;
}

int main(){
	vector<int> nums = {11,15,6,8,9,10};
	if(search_sum(nums, 16))
		cout<<"There are 2 numbers whose sum is 16"<<endl;
	else
		cout<<"There are no such combination whose sum is 16"<<endl;
	
	if(search_sum(nums, 30))
		cout<<"There are 2 numbers whose sum is 30"<<endl;
	else
		cout<<"There are no such combination whose sum is 30"<<endl;
	return 0;
}

