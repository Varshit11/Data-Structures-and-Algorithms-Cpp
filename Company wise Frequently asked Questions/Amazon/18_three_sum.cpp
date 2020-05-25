/* C++ program to solve 3Sum problem
Problem Statement - https://leetcode.com/problems/3sum/
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    int N = nums.size();
    sort(nums.begin(), nums.end());
    int i = 0;
    while(i<N-2){
        while(i-1>=0 && i<N-2 && nums[i] == nums[i-1]) ++i;
        int left = i+1, right = N-1, cur_ele = nums[i];
        while(left<right){
            int sum = cur_ele + nums[left] + nums[right];
            if(sum == 0){
                vector<int> temp = {cur_ele, nums[left], nums[right]};
                ans.push_back(temp);
                ++left;
                --right;
                while(left<right && nums[left] == nums[left-1]) ++left;
                while(left<right && nums[right] == nums[right+1]) --right;
            }
            else if(sum > 0) {
                --right;
                while(left<right && nums[right] == nums[right+1]) --right;
            }
            else {
                ++left;
                while(left<right && nums[left] == nums[left-1]) ++left;
            }
        }
        ++i;
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> ans = threeSum(nums);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

