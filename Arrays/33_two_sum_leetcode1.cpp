/* C++ program to solve 2 sum problem
Problem Statement - https://leetcode.com/problems/two-sum/
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> m;
    vector<int> ans(2);
    for(int i = 0; i<nums.size(); i++){
        if(m.find(target-nums[i]) != m.end()){
            ans[0] = m[target-nums[i]];
            ans[1] = i;
            return ans;
        }
        m[nums[i]] = i;
    }
    return ans;
}
    
int main(){
	vector<int> nums = {2,7,11,15};
	vector<int> ans = twoSum(nums, 9);
	cout<<ans[0]<<" "<<ans[1]<<endl;
	return 0;
}
