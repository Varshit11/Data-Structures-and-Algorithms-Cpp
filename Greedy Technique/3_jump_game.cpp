/* C++ program to solve jump game problem
Problem Statement - https://leetcode.com/problems/jump-game/
*/

#include<bits/stdc++.h>
using namespace std;

// this is very important problem, there are many ways from backtracking and DP also but this 
// is most efficient solution 
bool canJump(vector<int>& nums) {
    int last_pos = nums.size()-1;
    for(int i = nums.size()-1; i>=0; i--){
        if(i+nums[i] >= last_pos) last_pos = i;
    }
    return last_pos == 0;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration..
	vector<int> nums = {2,3,1,1,4};
	vector<int> nums2 = {3,2,1,0,4};
	if(canJump(nums)) cout<<"We can reach the last index "<<endl;
	else cout<<"We cannot reach the last index "<<endl;
	
	if(canJump(nums2)) cout<<"We can reach the last index "<<endl;
	else cout<<"We cannot reach the last index "<<endl; 
	
	return 0;
}

