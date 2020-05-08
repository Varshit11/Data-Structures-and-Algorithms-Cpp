/* C++ program to solve Levenstein/Edit Distance Problem
*/

#include<iostream>
#include<string>
using namespace std;

int min(int a, int b, int c){
	return a>b ? (b>c ? c : b) : (a>c ? c : a);
}

int levenstein_recursion(string &s1, string &s2, int m, int n){ // m and n will be indexes for string s1 and s2 respectively
	if(m == 0) return n;
	else if(n == 0) return m;
	else if(s1[m-1] == s2[n-1]) return levenstein_recursion(s1,s2, m-1, n-1);
	else return min(1+levenstein_recursion(s1,s2,m-1, n-1), 1+levenstein_recursion(s1,s2,m-1,n), 1+levenstein_recursion(s1,s2,m,n-1));
}

int levenstein_bottom_up(string &s1, string &s2){
	int temp[s1.length()+1][s2.length()+1]; // extra row accounts for s1 = '', extra column s2 = ''
	for(int i = 0; i<= s1.length(); i++){
		for(int j = 0; j<=s2.length();j++){
			if(i == 0) temp[i][j] = j;
			else if(j == 0) temp[i][j] = i;
			else if(s1[i-1] == s2[j-1]) temp[i][j] = temp[i-1][j-1];
			else temp[i][j] = 1+min(temp[i-1][j-1], temp[i-1][j], temp[i][j-1]);
		}
	}
	return temp[s1.length()][s2.length()];
}

int main(){
	string s1("abc");
	string s2("defg");
	int dist_recur = levenstein_recursion(s1, s2, s1.length(), s2.length());
	int dist_dp = levenstein_bottom_up(s1, s2);
	cout<<"Using recursion the levenstein distance is "<<dist_recur<<endl;
	cout<<"Using bottoom up DP the levenstein distance is "<<dist_dp<<endl;
	return 0;
}

