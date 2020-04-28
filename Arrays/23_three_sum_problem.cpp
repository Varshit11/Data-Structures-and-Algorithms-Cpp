/* C++ program to solve 3Sum problem 
Problem Statement - https://leetcode.com/problems/3sum/
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int i, left, right, N = nums.size(), sum;
    set<vector<int>> s;
    vector<int> temp(3);
    sort(nums.begin(), nums.end());
    for(i=0;i<N-2;i++){
        left = i+1;
        right = N-1;
        while(left<right){
            sum = nums[i]+nums[left]+nums[right];
            if(sum == 0){
                temp[0] = nums[i];
                temp[1] = nums[left];
                temp[2] = nums[right];
                s.insert(temp);
                left++;
                right--;
            }
            else if(sum > 0) right--;
            else left++;
        }
    }
    vector<vector<int>> ans(s.begin(), s.end());
    return ans;
}

int main(){
	// passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {-1,0,1,2,-1,-4};
	vector<vector<int>> ans = threeSum(nums);
	for(int i =0;i<ans.size();i++){
		for(int j = 0; j<ans[i].size();j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

