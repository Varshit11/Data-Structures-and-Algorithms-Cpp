/* C++ program to find the length of Longest Substring Without Repeating Characters
Problem Statement - https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) return 0;
    if(s.length() == 1) return 1;
    map<char, int> m;
    int i = 0, j = 0, max_len = INT_MIN;
    while(i<s.length()){
        if(m.find(s[i]) == m.end()){
            m[s[i]]++;
            i++;
        }else{
            max_len = max(max_len, i-j);
            m.erase(s[j]);
            j++;
        }
    }
    return max(max_len, i-j);
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s = "abcabcbb";
	cout<<"The length of longest substring without repeating characters is "<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}

