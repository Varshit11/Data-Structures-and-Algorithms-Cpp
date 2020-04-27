/* C++ program to find increasing triplet subsequence. If it exists. Given an array
find if there is triplet, such that A[i] < A[j] < A[k] and i<j<k 
Problem Statement - https://leetcode.com/problems/increasing-triplet-subsequence/
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> increasingTriplet(vector<int> &nums){
	int min_index = 0, low = -1, mid = -1;
	vector<vector<int>> ans;
	vector<int> temp(3);
    for(int i = 1; i<nums.size(); i++){
        if(nums[i] <= nums[min_index])
            min_index = i;
        else if(mid == -1){
            mid = i;
            low = min_index;
        }
        else if(nums[i] <= nums[mid]){
            low = min_index;
            mid = i;
        }
        else{
        	temp[0] = nums[low];
        	temp[1] = nums[mid];
        	temp[2] = nums[i];
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case used here as demonstration.
	vector<int> nums = {5,4,3,7,6,1,9};
	vector<vector<int>> ans = increasingTriplet(nums);
	if(!ans.size())
		cout<<"There are no increasing triplet subsequence in the array "<<endl;
	else{
		cout<<"The increasing triplet subsequence in the array is "<<endl;
		for(int i = 0; i<ans.size(); i++){
			for(int j = 0; j<ans[i].size(); j++)
				cout<<ans[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

