/* C++ program to print Longest palindromic Substring
Problem Statement - https://leetcode.com/problems/longest-palindromic-substring/
*/

#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
    if(s.length() == 0 || s.length() == 1) return s;
    vector<vector<bool>> mat(s.length(), vector<bool>(s.length(), false));
    int start = 0, str_length = 1;
    for(int i = 0; i<s.length(); i++) mat[i][i] = true;
    for(int i = 0; i<s.length()-1; i++) {
        if(s[i] == s[i+1]) {
            mat[i][i+1] = true;
            start = i;
            str_length = 2;
        }
    }
        
    for(int k = 3; k<=s.length(); k++){
        for(int i = 0; i<=s.length()-k; i++){
            int j = i+k-1;
            if(s[i] == s[j] && mat[i+1][j-1]){
                mat[i][j] = true;
                start = i;
                str_length = k;
            }
        }
    }
    string temp(s.begin()+start, s.begin()+start+str_length);
    return temp;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "babad";
	cout<<"The longest palindromic substring of this string is "<<longestPalindrome(s)<<endl;
	return 0;
}

