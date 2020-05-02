/* C++ program to solve Decode ways problem of leetcode
Problem Statement - https://leetcode.com/problems/decode-ways/
*/

#include<bits/stdc++.h>
using namespace std;

map<int, int> m;
int decode(int index, string &s){
    int result;
    if(index == s.length()) {
    	return 1;
	}
    if(s[index] == '0') return 0;
    if(index == s.length()-1) return 1;
    if(m.find(index) != m.end()) return m[index];
    if(stoi(s.substr(index, 2)) <= 26)
        result = decode(index+1, s) + decode(index+2, s);
    else
        result = decode(index+1, s);
    m[index] = result;
    return result;
}
int numDecodings(string s) {
    if(s.length() == 0) return 0;
    return decode(0, s);
}
    
int main(){
	// code passed all test cases on leetcode, one of the test case is shown here for demonstration
	string s = "12120";
	cout<<numDecodings(s)<<endl;
	return 0;
}
