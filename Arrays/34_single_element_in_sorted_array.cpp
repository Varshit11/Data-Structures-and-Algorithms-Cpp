/* C++ program to find Single Element in a Sorted Array, solve this in O(logN) time and O(1) space.
Problem statement - https://leetcode.com/problems/single-element-in-a-sorted-array/
*/

#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int mid, l = 0, r = nums.size()-1;
    if(nums.size() == 1) return nums[0];
    else{
        while(r>l){
            mid = (l+r)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid%2 == 0){
                if(nums[mid] == nums[mid-1]) r = mid;
                else l = mid;
            }
            else{
                if(nums[mid] == nums[mid-1]) l = mid+1;
                else r = mid-1;
            }
        }
    }
    return nums[l];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {1,1,2,2,4,4,5,6,6};
	cout<<"The single element in the sorted array is "<<singleNonDuplicate(nums)<<endl;
	return 0;
}

