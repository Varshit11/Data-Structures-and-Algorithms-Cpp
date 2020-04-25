/* C++ program to find top k frequent elements 
Problem statement - https://leetcode.com/problems/top-k-frequent-elements/
*/

#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

map <int, int> m;
vector<int> topKFrequent(vector<int>& nums, int k) {
    for(int i = 0; i<nums.size();i++)
        m[nums[i]]++;

    vector<int> ans;
    priority_queue <pair<int, int>> p;
    for(auto i = m.begin(); i!= m.end(); i++){
        p.push(make_pair(i->second, i->first));
    }
    for(int i = 0; i<k; i++){
        ans.push_back(p.top().second);
        p.pop();
    }
    return ans;
}

int main(){
	// only one test case is used for demonstration here, the code is tested on leetcode and 
	// passed all the test cases.
	vector<int> nums = {1,1,1,2,2,3};
	vector<int> ans = topKFrequent(nums, 2);
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	return 0;
}

