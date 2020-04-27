/* C++ program to Replace Elements with Greatest Element on Right Side.
Problem statement - https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    if(arr.size() == 0)
        return arr;
    int i, MAX, j = arr.size()-1;        
    vector<int> ans(arr.size());
    ans[j--] = -1;
    MAX = arr[arr.size()-1];
    for(int i = arr.size()-2; i>0;i--){
        ans[j--] = MAX;
        if(MAX < arr[i])
            MAX = arr[i];
    }
    if(arr.size() > 1)
        ans[j] = MAX;
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> arr = {17,18,5,4,6,1};
	vector<int> ans = replaceElements(arr);
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<" ";
	return 0;
}

