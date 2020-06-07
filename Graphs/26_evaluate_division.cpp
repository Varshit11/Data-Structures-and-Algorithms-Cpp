/* C++ program to solve Evaluate Division problem
Problem Statement - https://leetcode.com/problems/evaluate-division/
*/

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;

bool dfs(string s1, string s2, map<string, vector<pair<string, double>>> &m, map<string, bool>& visited, double &cur_ans){
    visited[s1] = true;
    if(s1 == s2) return true;
    vector<pair<string, double>> adj_list = m[s1];
    for(int i = 0; i<adj_list.size(); i++){
        string temp = adj_list[i].first;
        double d = adj_list[i].second;
        if(!visited[temp]){
            cur_ans *= d;
            if(!dfs(temp, s2, m, visited, cur_ans)) cur_ans/= d;
            else return true;
        }
    }
    return false;
}
    
vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    map<string, vector<pair<string, double>>> m;
    for(int i = 0; i<equations.size(); i++){
        m[equations[i][0]].push_back({equations[i][1], values[i]});
        m[equations[i][1]].push_back({equations[i][0], 1/values[i]});
    }
        
    map<string, bool> visited;
    for(auto x: m){
        visited[x.first] = false;
    }
        
    vector<double> ans;
    for(int i = 0; i<queries.size(); i++){
        string s1(queries[i][0]);
        string s2(queries[i][1]);
        if(m.find(s1) == m.end() || m.find(s2) == m.end()){
            ans.push_back(-1);
            continue;
        }
        map<string, bool> temp(visited);
        double cur_ans = 1;
        bool t = dfs(s1, s2, m, temp, cur_ans);
        if(!t) ans.push_back(-1);
        else ans.push_back(cur_ans);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<string>> equations = {{"a", "b"}, {"b","c"}};
	vector<double> values = {2.0, 3.0};
	vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a","a"},{"x","x"}};
	
	vector<double> ans = calcEquation(equations, values, queries);
	
	for(int i = 0; i<ans.size(); i++){
		cout<<ans[i]<<"  ";
	}
	return 0;
}

