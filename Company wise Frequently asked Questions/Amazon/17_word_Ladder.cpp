/* C++ program to solve word ladder problem 
Problem Statement - https://leetcode.com/problems/word-ladder/
*/

#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
    if(beginWord.length() == 0 || endWord.length() == 0) return 0;
    map<string, vector<string>> combo;
    for(auto x: wordList){ // creating the combo dictionary for lookup
        for(int i = 0; i<x.length(); i++){
            string temp(x.begin(), x.begin()+i);
            string temp2(x.begin()+i+1, x.end());
            temp += ('*'+temp2);
            combo[temp].push_back(x);
        }
    }
        
    queue<pair<string, int>> q; // for bfs
    q.push(make_pair(beginWord, 1)); // beginWord has level 1
    map<string, bool> visited; // for avoiding loops
    visited[beginWord] = true;
    while(!q.empty()){
        string cur_word = q.front().first;
        int cur_level = q.front().second;
        q.pop();
        for(int i = 0; i<cur_word.length(); i++){
            string temp(cur_word.begin(), cur_word.begin()+i);
            string temp2(cur_word.begin()+i+1, cur_word.end());
            temp+= ('*'+temp2);
            vector<string> combo_list = combo[temp];
            for(auto x: combo_list){
                if(x == endWord) return cur_level+1;
                if(visited.find(x) == visited.end()){
                    visited[x] = true;
                    q.push(make_pair(x, cur_level+1));
                }
            }
            combo.erase(temp);
        }
    }
    return 0;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	string beginWord = "leet";
	string endWord = "code";
	vector<string> wordList = {"lest","leet","lose","code","lode","robe","lost"};
	cout<<ladderLength(beginWord, endWord, wordList);
	return 0;
}
