/* C++ program to solve Permutations in string problem
Problem Statement - https://leetcode.com/problems/permutation-in-string/
*/

#include<bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;
    int arr1[26] = {0};
    int arr2[26] = {0};
    int count = 0;
    for(int i = 0; i<s1.length(); i++){
        arr1[s1[i]-'a']++;
        arr2[s2[i]-'a']++;
    }
    
    for(int i = 0; i<26;i++) if(arr1[i] == arr2[i]) count++;
    
    for(int i = 0; i<s2.length()-s1.length(); i++){
    	int l = s2[i]-'a';
    	int r = s2[i+s1.length()] - 'a';
    	if(count == 26) return true;
    	arr2[r]++;
    	if(arr2[r] == arr1[r]) count++;
    	else if(arr2[r] == arr1[r]+1) count--;
    	arr2[l]--;
    	if(arr2[l] == arr1[l]) count++;
    	else if(arr2[l] == arr1[l]+1) count--;
    }
    return count == 26;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string s1 = "ab";
	string s2 = "eidbaooo";
	if(checkInclusion(s1,s2)) cout<<"First string permutation is substring of second string "<<endl;
	else cout<<"First string permutation is not substring of seconod string "<<endl;
	return 0;
}

