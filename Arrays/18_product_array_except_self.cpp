/* C++ program to solve Product of Array Except Self problem. 
Problem Statement - https://leetcode.com/problems/product-of-array-except-self/
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int left_prod = 1,i, temp = 1;
    vector<int> ans(nums.size());
    for(i=nums.size()-1;i>=0;i--){
        temp *= nums[i];
        ans[i] = temp; // for now it will store all the right product
    }
    for(i=0;i<nums.size()-1;i++){
        ans[i] = left_prod*ans[i+1];
        left_prod*= nums[i];
    }
    ans[nums.size()-1] = left_prod;
    return ans;
}

int main(){
	vector<int> nums = {1,2,3,4};
	vector<int> ans = productExceptSelf(nums);
	cout<<"The product of elements of array except self is "<<endl;
	for(int i = 0; i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
