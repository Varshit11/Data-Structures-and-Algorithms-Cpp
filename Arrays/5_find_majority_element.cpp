/* C++ program to find the majority element in array, element which occurs more than
N/2 times in an array.
Problem statement - https://leetcode.com/problems/majority-element/
*/

// there are many approaches, we will use most efficient Boyer Moore Voting algorithm
// Time = O(1) and space = O(1)

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int count = 0, m = 0, i, v = 0;
    for(i=0;i<nums.size();i++){
        if(count == 0){
            count++;
            m = nums[i];
        }else{
            if(m == nums[i])
                count++;
            else
                count--;
        }
    }
    for(i=0;i<nums.size();i++){
    	if(nums[i] == m)
    		v++;
	}
	if(v > nums.size()/2)
		return m;
	else
		return INT_MIN;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int ans;
	vector<int> nums = {2,2,1,1,1,2,2};
	if((ans = majorityElement(nums)) > INT_MIN)
		cout<<"The majority element is "<<ans<<endl;
	else
		cout<<"There is no majority element "<<endl;
	return 0;
}

