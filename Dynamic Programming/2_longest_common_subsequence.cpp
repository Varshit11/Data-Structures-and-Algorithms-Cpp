/* C++ program to solve Longest Common Subsequence (LCS) problem
We will solve using both recursive and Dynamic programming approach
Problem Statement - https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/
*/

#include<iostream>
#include<string>
using namespace std;

// recursive approach, time complexity O(2^(m+n)) The worst case happens when there is no common sub sequence present in 
// S1 and S2 ( that is LCS is 0) and each recursive call will end up in two recursive calls. So worst case space complexity will be O(m+n).
int lcs_recursive(string &s1, string &s2, int m, int n){ // m and n are lengths of string s1 and s2 respectively
	if(m == 0 || n == 0) return 0;
	if(s1[m-1] == s2[n-1]) return 1+lcs_recursive(s1, s2, m-1, n-1);
	else return max(lcs_recursive(s1,s2,m,n-1), lcs_recursive(s1,s2,m-1, n));
}

int lcs_DP(string &s1, string &s2){ // time complexity O(m*n) and space complexity O(m*n) as extra matrix is used here
	int mat[s1.length()+1][s2.length()+1] = {0};
	for(int i = 0; i<=s1.length(); i++){
		for(int j = 0; j<=s2.length(); j++){
			if(i == 0 || j == 0) mat[i][j] = 0;
			else if(s1[i-1] == s2[j-1]) mat[i][j] = 1+mat[i-1][j-1];
			else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
		}
	}
	return mat[s1.length()][s2.length()];
}

int main(){
	string s1("AGGTAB");
	string s2("GXTXAYB");
	int recur = lcs_recursive(s1, s2, s1.length(), s2.length());
	int dp = lcs_DP(s1, s2);
	cout<<"The length of longest common subsequence using recursive approach "<<recur<<endl;
	cout<<"The length of longest common subsequence using DP approach "<<dp<<endl;
	return 0;
}

