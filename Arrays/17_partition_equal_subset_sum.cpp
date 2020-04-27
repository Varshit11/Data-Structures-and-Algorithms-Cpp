/* C++ program to  partition the array such that each subset has a equal sum. 
For ex. A = {1,2,3,4,5,5}, the 2 subsets, 1,2,3,4 and 5,5 both has a sum of 10. Check if we can
do such partition in the array. Note we are interested in continous subarray, not subsequence.
*/

#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int> &nums){
	int sum1 = nums[0], sum2 = nums[nums.size()-1], i = 0, j = nums.size()-1;
	while(i<j){
		if(sum1 == sum2)
			return true;
		else if(sum1 < sum2)
			sum1 += nums[++i];
		else
			sum2 += nums[--j];
	}
	return false;
}

int main(){
	vector<int> nums = {1,2,3,4,5,5};
	canPartition(nums) ? cout<<"We can split the array in 2 halves with equal sum" : 
		cout<<"We cannot split the array in 2 halves with equal sum"<<endl;
	
	return 0;
}
