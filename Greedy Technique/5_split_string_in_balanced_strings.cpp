/* C++ program to Split a string in balanced strings
Problem Statement - https://leetcode.com/problems/split-a-string-in-balanced-strings/
*/

#include<bits/stdc++.h>
using namespace std;

int balancedStringSplit(string s) {
    int balance = 0, index = 0, ans = 0;
    while(index < s.length()){
        if(s[index] == 'L') ++balance;
        else --balance;
        if(balance == 0) ++ans;
        ++index;
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "RLRRLLRLRL";
	cout<<"The maximum amount of splitted balanced strings are "<<balancedStringSplit(s)<<endl;
	return 0;
}

