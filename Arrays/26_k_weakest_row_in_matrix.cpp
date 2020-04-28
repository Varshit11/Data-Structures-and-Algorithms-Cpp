/* C++ program to find the k weakest rows in a matrix
Problem statement - https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    set <pair<int, int>> s; // pair of count and index
    for(int i = 0; i<mat.size(); i++){
        int count = 0;
        for(int j = 0; j<mat[0].size(); j++){
            count+= mat[i][j];
        }
        s.insert(make_pair(count, i));
    }
    vector<int> ans;
    int c = 0;
    for(auto x: s){
        if(c == k) break;
        ans.push_back(x.second);
        ++c;
    }
    return ans;
}

int main(){
	// code passed all the test case on leetcode, one test case is shown here for demonstration.
	vector<vector<int>> mat = {{1,1,0,0,0}, {1,1,1,1,0}, {1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1}};
	vector<int> ans = kWeakestRows(mat, 3); // k is 3.
	for(int i = 0; i<3;i++) // k is 3 here so loop running till 3
		cout<<ans[i]<<" ";
	return 0;
}
    
