/* C++ program to print longest palindromic sub string 
Problem Statement - https://leetcode.com/problems/longest-palindromic-substring/
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string longestPalindrome(string s) {
    if(s.length() == 0 || s.length() == 1) return s;
    int start = 0, max_length = 1;
    bool m[s.length()][s.length()];
    for(int i = 0; i<s.length(); i++) m[i][i] = true;
    for(int i = 0; i<s.length()-1; i++){
        if(s[i] == s[i+1]){
            m[i][i+1] = true;
            start = i;
            max_length = 2;
        }else m[i][i+1] = false;
    }
        
    for(int k = 3; k<=s.length(); k++){
        for(int i = 0; i<=s.length()-k;i++){
            int j = i+k-1;
            if(s[i] == s[j] && m[i+1][j-1]){
                m[i][j] = true;
                if(k > max_length){
                    start = i;
                    max_length = k;
                }
            }else m[i][j] = false;
        }
    }
    string ans(s.begin()+start, s.begin()+start+max_length);
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "babadada";
	cout<<"The longest palindromic sub string for this string is "<<longestPalindrome(s)<<endl;
	return 0;
}
