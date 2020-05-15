/* C++ program to solve 2 sum problem
Problem Statement - https://leetcode.com/problems/two-sum/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans(2);
    map<int, int> m;
    for(int i = 0; i<nums.size(); i++){
        if(m.find(target-nums[i]) != m.end()){
            ans[0] = m[target-nums[i]];
            ans[1] = i;
            break;
        }
        m[nums[i]] = i;
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {2,7,11,15};
	vector<int> ans = twoSum(nums, 9);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}
