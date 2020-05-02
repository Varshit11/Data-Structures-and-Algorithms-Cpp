/* C++ program to Sort Characters By Frequency
Problem Statement - https://leetcode.com/problems/sort-characters-by-frequency/
*/

#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

struct compare_count{
    bool operator()(pair <char, int> &v1, pair <char, int> &v2){
        return v1.second < v2.second;
    }
};
    
void frequencySort(string& s) {
    map <char, int> m;
    priority_queue <pair<char, int>, vector<pair<char, int>>, compare_count> pq;
    int i;
    for(i=0;i<s.length(); i++) m[s[i]]++;
    for(auto x = m.begin(); x!=m.end(); x++) pq.push(make_pair(x->first, x->second));
    s.clear();
    while(!pq.empty()){
        int j = pq.top().second;
        while(j-->0) s+= pq.top().first;
        pq.pop();
    }
}

int main(){
	// code passed all test cases on leetcode, one of the test case is shown here for demonstration
	string s = "tree";
	frequencySort(s);
	cout<<s<<endl;
	return 0;
}
