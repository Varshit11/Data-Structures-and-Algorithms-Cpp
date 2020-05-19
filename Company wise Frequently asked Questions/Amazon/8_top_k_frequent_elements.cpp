/* C++ program to find top K frequent elements
Problem Statement - https://leetcode.com/problems/top-k-frequent-elements/
*/

#include<bits/stdc++.h>
using namespace std;

map<int, int> m;

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}
    
void max_heapify(vector<int> &temp, int index){
    int left = 2*index+1;
    int right = 2*index+2;
    int largest = index;
    if(left<temp.size() && m[temp[largest]] < m[temp[left]]) largest = left;
    if(right<temp.size() && m[temp[largest]] < m[temp[right]]) largest = right;
    if(largest != index) {
        swap(temp[index], temp[largest]);
        max_heapify(temp, largest);
    }else return;
}
    
void build_max_heap(vector<int> &temp){
    for(int i = temp.size()/2-1; i>=0; i--) max_heapify(temp, i);
}
    
void remove_top(vector<int> &temp){
    if(temp.size() == 0) return;
    swap(temp[0], temp[temp.size()-1]);
    temp.pop_back();
    max_heapify(temp, 0);
}
    
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> ans;
    vector<int> temp;
    if(k>nums.size()) return ans;
    for(int i = 0; i<nums.size(); i++) m[nums[i]]++;
    for(auto i = m.begin(); i!=m.end(); i++) temp.push_back(i->first);
    build_max_heap(temp);
    for(int i = 0; i<k; i++){
        ans.push_back(temp[0]);
        remove_top(temp);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;
	vector<int> ans = topKFrequent(nums, 2);
	for(int i = 0; i<k; i++) cout<<ans[i]<<" ";
	return 0;
}
	
