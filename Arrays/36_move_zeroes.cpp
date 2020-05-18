/* C++ program to solve Move zeroes problem
Problem Statement - https://leetcode.com/problems/move-zeroes/
*/

#include<iostream>
#include<vector>
using namespace std;

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}
    
void moveZeroes(vector<int>& nums) {
    if(nums.size() == 0) return;
    int non_zero = -1;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i] != 0){
            swap(nums[i], nums[non_zero+1]);
            ++non_zero;
        }
    }
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {0,1,0,3,1,2};
	moveZeroes(nums);
	for(int i = 0; i<nums.size(); i++) cout<<nums[i]<<" ";
	return 0;
}

