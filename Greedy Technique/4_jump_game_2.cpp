/* C++ program to solve Jump game 2 problem
Problem Statement - https://leetcode.com/problems/jump-game-ii/
*/

#include<iostream>
#include<vector>
using namespace std;

// I will be writing 2 solutions for this problem, the first solution is O(N^2) and the second
// and the most efficient solution is O(N) time. This is very good problem.

int min(int a, int b){
    return a > b ? b : a; 
}
  
int jump(vector<int>& nums) { // O(N^2) solution
    vector<int> jumps(nums.size(), 0);
    for(int i = nums.size()-2; i>=0; i--){
        int temp = min(i+nums[i], nums.size()-1);
        int min_cur = INT_MAX;
        for(int j = i+1; j<=temp; j++){
            min_cur = min(min_cur, jumps[j]);
        }
        if(min_cur == INT_MAX) jumps[i] = min_cur;
        else jumps[i] = 1+min_cur;
    }
    return jumps[0];
}

int jump_most_efficient(vector<int>& nums) { // O(N) solution
    int jumps = 0, cur_end = 0, cur_farthest = 0;
    for(int i = 0; i<nums.size()-1; i++){
        cur_farthest = max(cur_farthest, i+nums[i]);
        if(i == cur_end){
            ++jumps;
            cur_end = cur_farthest;
        }
    }
    return jumps;
}

int main(){
	/* code passed 91/92 cases on leetcode for O(N^2) solution, last test case there was 
	 time limit exceeded as the size of array was 25000, for O(N) the code passed all 
	 test cases, second solution is very creative */
	vector<int> nums = {2,3,1,1,4};
	cout<<"The minimum number of steps to reach last index is "<<jump_most_efficient(nums)<<endl;
	return 0;
}

