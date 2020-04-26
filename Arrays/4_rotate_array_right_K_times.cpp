/* Rotate array right K times 
Problem statement - https://leetcode.com/problems/rotate-array/
*/
/* there are many approaches to solve this problem, some of them are - 
1. Make function rotate once, temp = a[N-1] and then loop a[i+1] = a[i] and lastly, 
a[0] = temp, do this K times, time = O(N*k) space = O(1)
2. Use extra K space and store the last K elements, now run a loop N-K times and store
starting N-K elements in the last, and then copy the elements of extra space in starting of array
Time = O(N), space = O(N).
3. Reverse the last K elements, reverse the first N-K element, lastly, reverse the
whole array, time = O(N) and space = O(1) 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<int>& nums, int k) {
    if(nums.size() == 1 || nums.size() == 0 || k == 0)
        return;
    k = k%(nums.size());
    reverse(nums.begin(), nums.begin()+nums.size()-k); // build in C++ reverse function
    reverse(nums.begin()+nums.size()-k, nums.end());
    reverse(nums.begin(), nums.end());
}

int main(){
	// code tested on leetcode, for demonstration here taking one test case.
	vector<int> nums = {1,2,3,4,5,6,7};
	rotate(nums, 3); // rotate nums to right 3 times
	for(int i =0; i<nums.size(); i++)
		cout<<nums[i]<<" "; // display 5 6 7 1 2 3 4
	return 0;
}

