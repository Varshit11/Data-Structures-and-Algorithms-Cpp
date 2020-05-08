/* C++ program to solve word break problem
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

bool word_break_recursion(map<string, int> &m, string s){
	if(s.length() == 0) return true;
	bool f = false;
	for(int i = 0; i<s.length(); i++){
		string temp1(s.begin(), s.begin()+i);
		string temp2(s.begin()+i, s.end());
		if(m.find(temp2) == m.end()) continue;
		if(word_break_recursion(m, temp1)) return true; 
	}
	return false;
}

bool word_break(map<string, int> &m, string s){
	bool dp[s.length()+1];
	s[0] = true;
	for(int i = 1; i<=s.length(); i++){
		for(int j = 0; j<i; j++){
			string temp1(s.begin()+j, s.begin()+i);
			if(dp[j] && m.find(temp1) != m.end()){
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.length()];
}

int main(){
	map<string, int> m;
	string s = "helloworld";
	m.insert({"h", 1});
	m.insert({"he",1});
	m.insert({"e",1});
	m.insert({"llo",1});
	m.insert({"world",1});
	if(word_break_recursion(m, s)) cout<<"The word can be made from hashtable "<<endl;
	else cout<<"The word cannot be made from hashtable"<<endl;
	return 0;
}
