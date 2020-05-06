/* C++ program to find the longest palindromic sub sequence using both recursion and bottom up DP */

#include<iostream>
#include<string>
using namespace std;


int longest_palindromic_sequence_recursive(string &s, int start, int end){
	if(end < start) return 0;
	else if(start == end) return 1;
	else if(s[start] == s[end]) return 2+longest_palindromic_sequence_recursive(s, start+1, end-1);
	else return max(longest_palindromic_sequence_recursive(s, start+1, end), longest_palindromic_sequence_recursive(s, start, end-1));
}

int longest_palindromic_sequence_dp(string &s){
	int m[s.length()][s.length()] = {0};
	int i, j, ls;
	for(i=0;i<s.length();i++) m[i][i] = 1;
	for(ls=2;ls<=s.length();ls++){
		for(i=0;i<=s.length()-ls;i++){
			j = i+ls-1;
			if(s[i] == s[j] && ls == 2) m[i][j] = 2;
			else if(s[i] == s[j]) m[i][j] = m[i+1][j-1]+2;
			else m[i][j] = max(m[i+1][j], m[i][j-1]);
		}
	}
	return m[0][s.length()-1];
}

int main(){
	string s = "abcbca";
	cout<<"The longest palindromic sequence length using dp is "<<longest_palindromic_sequence_dp(s)<<endl;
	cout<<"The longest palindromic sequence length using recursion is "<<longest_palindromic_sequence_recursive(s, 0, s.length()-1)<<endl;
	return 0;
}

