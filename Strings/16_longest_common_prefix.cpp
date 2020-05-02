/* C++ program to find Longest Common Prefix in a vector of strings
Problem Statement - https://leetcode.com/problems/longest-common-prefix/
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];
    string ans = strs[0];
    int i, j;
    for(i=1;i<strs.size();i++){
        int k = 0;
        string temp;
        for(j=0;j<strs[i].length(); j++){
            if(k<ans.length() && strs[i][j] == ans[k]) {
                temp+= ans[k++];
            }
            else break;
        }
        ans = temp;
        if(ans.length() == 0) return "";
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<string> strs = {"flower","flow","flight"};
	string ans = longestCommonPrefix(strs);
	cout<<ans<<endl;
	return 0;
}
