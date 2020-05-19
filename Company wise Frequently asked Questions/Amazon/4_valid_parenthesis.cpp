/* C++ program to Valid Parentheses
Problem Statement - https://leetcode.com/problems/valid-parentheses/
*/

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(int i = 0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else{
            if(st.empty()) return false;
            else if((s[i] == ')' && st.top() == '(') || (s[i] == ']' && st.top() == '[') || (s[i] == '}' && st.top() == '{')) st.pop();
            else return false;
        }
    }
    return st.empty();
}

int main(){
	//code passed all test cases on leetcode, one test case is shown here for demonstration
	string s("(){}[]");
	if(isValid(s)) cout<<"The string is valid "<<endl;
	else cout<<"The string is not valid "<<endl;
	return 0;
}

