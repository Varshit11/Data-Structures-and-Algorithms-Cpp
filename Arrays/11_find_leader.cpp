/* C++ program to find leaders in an array. for ex. if A = [10,6,3,1,7,9], A 
leader is the element which is greater than all the elements to its right, for
the rightmost element, print the element as it is, because there is no right
element after that. In the example below the leader is [10,9] as all elements are
less than 10 after that and since 6,3,1,7 are less than 9 so they are no the 
leader, 9 is the leader as it is rightmost element */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int > find_leader(vector<int> &nums){
	vector<int> ans;
	int MAX = INT_MIN;
	for(int i = nums.size()-1; i>=0;i--){
		if(MAX < nums[i]){
			MAX = nums[i];
			ans.push_back(nums[i]);
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(){
	vector<int> nums = {8,4,2,3,1,5,4,2};
	vector<int> ans = find_leader(nums);
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	return 0;
}

