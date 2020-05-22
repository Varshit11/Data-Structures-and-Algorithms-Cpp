/* C++ program to solve word break problem
Problem Statement - https://leetcode.com/problems/word-break/
*/

#include<bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.length()+1, false);
    dp[0] = true;
    for(int i = 1; i<=s.length(); i++){
        for(int j = 0; j<i; j++){
            string temp(s.begin()+j, s.begin()+i);
            if(dp[j] && find(wordDict.begin(), wordDict.end(), temp) != wordDict.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	if(wordBreak(s, wordDict)) cout<<"We can break the string "<<endl;
	else cout<<"We cannot break the string"<<endl;
	return 0;
}
