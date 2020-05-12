/* C++ program to return all possible permutations, given a collection of distinct integers.
Problem Statement - https://leetcode.com/problems/permutations/
Time complexity - O(N*N!), space complexity - O(N!)
*/

#include<iostream>
#include<vector>
using namespace std;

void compute(vector<vector<int>> &ans, vector<int> nums, vector<int> &temp){
    if(nums.size() == 0){
        ans.push_back(temp);
        return;
    }
    else{
        for(int i = 0; i<nums.size(); i++){
            temp.push_back(nums[i]);
            vector<int> temp2(nums);
            temp2.erase(temp2.begin()+i);
            compute(ans, temp2, temp);
            temp.pop_back();
        }
    }
}
    
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    compute(ans, nums, temp);
    return ans; 
}

int main(){
	// code passed all test cases on leetcode, one of the test case is shown here for demonstration
	vector<int> nums = {1,2,3};
	vector<vector<int>> ans = permute(nums);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
}

