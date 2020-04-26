/* C++ program to find top k most frequent words 
Problem Statement - https://leetcode.com/problems/top-k-frequent-words/
*/

#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>
using namespace std;

struct Comparator{
    bool operator()(pair <int, string> a, pair <int, string> b){
          if(a.first != b.first) return (a.first < b.first);
        return (a.second > b.second);
        }
};
vector<string> topKFrequent(vector<string>& words, int k) {
    int i, count = 0;
    map <string, int> m;
    for(i=0;i<words.size();i++)
        m[words[i]]++;
    priority_queue < pair <int, string>, vector < pair <int, string> >, Comparator > p;
    for(auto x = m.begin(); x!=m.end(); x++){
        p.push(make_pair(x->second, x->first));
    }
    vector<string> ans;
    for(i=0;i<k;i++){
        ans.push_back(p.top().second);
        p.pop();
    }
    return ans;
}

int main(){
	int i;
	// code tested on leetcode and passed all the test cases, here taking 
	// one test case for demonstration
	vector<string> words  = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
	vector<string> ans = topKFrequent(words, 4); // top 4 most frequent
	for(i = 0; i<4;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}

