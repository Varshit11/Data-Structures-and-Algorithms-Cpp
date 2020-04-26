/* C++ program to Find the duplicate Number.
Problem Statement - https://leetcode.com/problems/find-the-duplicate-number/
*/

/* There are many approaches to solve this problem.
 1. Sort the array, if there are duplicates then they will be side by side
check nums[i] == nums[i-1]. Time = O(N*logN), Space = O(1), if inplace algo used.
2. Store it in hash and if the count of particular number is more than 1 return it.
Time = O(N) and Space = O(N)
3. There is more efficient algorithm called as Floyd Tortoise and Hare (Cycle Detection)
Search on google for this algo. We will implement this algo here. 
Time = O(N) and Space = O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

int find_duplicate(vector<int> &nums){
	int tortoise = nums[0];
	int hare = nums[0];
	while(tortoise != hare){
		tortoise = nums[tortoise];
		hare = nums[nums[hare]];
	}
	tortoise = nums[0];
	while(tortoise != hare){
		tortoise = nums[tortoise];
		hare = nums[hare];
	}
	return tortoise;	
}

int main(){
	// code tested on leetcode on all test cases. 
	vector<int> nums = {7, 2,1, 5, 9, 8, 7, 7, 4, 7};
	cout<<"The number which has duplicates in array is "<<find_duplicate(nums)<<endl;
	return 0;
}

