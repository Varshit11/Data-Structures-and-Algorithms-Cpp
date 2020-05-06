/* C++ program to print the longest palindromic sub sequence */

#include<iostream>
#include<string>
#include<algorithm> // for using reverse function
using namespace std;

string longestPalindrome(string& s) {
    int m[s.length()+1][s.length()+1];
    string ans;
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int i, j;
    for(i=0;i<=s.length();i++){
        for(j=0;j<=s.length();j++){
            if(i == 0 || j == 0) m[i][j] = 0;
            else if(s[i-1] == s2[j-1]) m[i][j] = 1+m[i-1][j-1];
            else m[i][j] = max(m[i][j-1], m[i-1][j]);
        }
    }
    i = s.length();
    j = s.length();
    string temp;
    while(i>0 && j>0){
        if(m[i][j] == m[i-1][j]) i--;
        else if(m[i][j] == m[i][j-1]) j--;
        else{
            ans+= s[i-1];
            i--;
            j--;
        }
    }
    return ans;       
}

int main(){
	string s = "abcbca";
	cout<<"The longest palindromic sub sequence is "<<longestPalindrome(s)<<endl;
	return 0;
}

