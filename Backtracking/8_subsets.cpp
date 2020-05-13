/* C++ program to solve subsets problem
Problem statement - https://leetcode.com/problems/subsets/
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    int sum = (int)pow(2, nums.size());
    vector<vector<int>> ans = {{}};
    int i = 1;
    while(i < pow(2, nums.size())){
        vector<int> temp;
        int count = nums.size()-1;
        int j = i;
        while(j>0){
            if(j%2 == 1) temp.push_back(nums[count]);
            j/=2;
            count--;
        }
        ans.push_back(temp);
        ++i;
    }
    return ans;
}
    
int main(){
	vector<int> nums = {1,2,3};
	vector<vector<int>> ans = subsets(nums);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++) cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
