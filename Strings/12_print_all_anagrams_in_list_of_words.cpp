/* C++ program to Print all anagrams in a list of words
Problem Statement - https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> print_all_anagrams(vector<string> &words){
	map<string, int> m;
	int i;
	string temp;
	vector<string> ans;
	vector<string> temp_word;
	for(i=0;i<words.size();i++){
		temp = words[i];
		sort(temp.begin(), temp.end());
		temp_word.push_back(temp);
		m[temp]++;
	}
	for(i=0;i<words.size(); i++) if(m[temp_word[i]] > 1) ans.push_back(words[i]);
	return ans;
}

int main(){
	vector<string> words = {"cat", "act", "man", "dog", "nam"};
	vector<string> ans = print_all_anagrams(words);
	for(int i = 0; i<ans.size(); i++)
		cout<<ans[i]<<endl;
	return 0;
}

