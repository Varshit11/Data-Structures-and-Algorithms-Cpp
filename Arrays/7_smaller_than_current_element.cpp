/* C++ program to find how Many Numbers Are Smaller Than the Current Number
Problem Statement - https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
*/

#include<iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    map <int, int> m;
    vector<int> ans;
    int i, sum = 0, temp;
    for(i = 0;i<nums.size(); i++)
        m[nums[i]]++;
    for(auto x = m.begin(); x!= m.end(); x++){
        if(x == m.begin()){
            sum = x->second;
            x->second = 0;
            continue;
        }
        temp = sum;
        sum += x->second;
        x->second = temp;
    }
    for(i=0;i<nums.size();i++){
        ans.push_back(m[nums[i]]);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, for demonstration one test is used here.
	vector<int> nums = {8,1,2,2,3};
	vector<int> ans = smallerNumbersThanCurrent(nums);
	for(int i = 0; i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}
