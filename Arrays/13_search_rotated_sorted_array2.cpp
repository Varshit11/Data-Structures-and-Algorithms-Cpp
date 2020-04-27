/* C++ program to search an element in rotated sorted array in O(logn) time. 
Problem statement - https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid]<= nums[right]){
            if(target > nums[mid] && target <= nums[right])
                left = mid+1;
            else
                right = mid-1;
        }
        else{
            if(target >= nums[left] && target < nums[mid])
                right = mid-1;
            else
            	left = mid+1;
        }
    }
    return -1;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {4,5,6,7,0,1,2};
	int ans = search(nums, 0);
	if(ans!=-1) cout<<"The index where 0 is found is "<<ans<<endl;
	return 0;
}

