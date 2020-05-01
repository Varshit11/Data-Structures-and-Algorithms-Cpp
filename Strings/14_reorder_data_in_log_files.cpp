/* C++ program to Reorder Data in Log Files
Problem Statement - https://leetcode.com/problems/reorder-data-in-log-files/
*/

#include<bits/stdc++.h>
using namespace std;

bool compare(pair<string, string>&v1, pair<string, string>&v2){
	return v1.second == v2.second ? v1.first<v1.first : v1.second < v2.second;
}

vector<string> reorderLogFiles(vector<string>& logs){
	vector<string> ans, digits;
	vector<pair<string, string>> letter;
	for(string&s: logs){
		int i = 0;
		while(s[i]!=' ')++i;
		if(isalpha(s[i+1])) letter.push_back(make_pair(s.substr(0, i), s.substr(i+1)));
		else digits.push_back(s);
	}
	sort(letter.begin(), letter.end(), compare);
	for(auto &x : letter) ans.push_back(x.first+ " "+x.second);
	for(string &s: digits) ans.push_back(s);
	return ans;
}
    
int main(){
	vector<string> logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
//	vector<string> logs = {"1 n u", "2 a g", "r 527", "j 893", "6 14", "6 82"};
	vector<string> ans = reorderLogFiles(logs);
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}    
