/* C++ program to find Longest Valid Parentheses
Problem Statement - https://leetcode.com/problems/longest-valid-parentheses/
*/

#include<iostream>
#include<string>
using namespace std;

int longestValidParentheses(string s) {
    if(s.length() == 0 || s.length() == 1) return 0;
    int m[s.length()], max_length = 0;
    m[0] = 0;
    for(int i = 1; i < s.length(); i++){
        m[i] = 0;
        if(s[i] == ')'){
            if(s[i-1] == '(') m[i] = (i >= 2 ? m[i-2] : 0) + 2;
            else if(i-m[i-1] > 0 && s[i-m[i-1]-1] == '('){
                m[i] = m[i-1] + ((i-m[i-1]) >= 2 ? m[i-m[i-1]-2] : 0) + 2;
            }
            max_length = max(max_length, m[i]);
        }
    }
    return max_length;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s(")()())");
	cout<<"The longest valid parenthesis is "<<longestValidParentheses(s)<<endl;
	return 0;
}
