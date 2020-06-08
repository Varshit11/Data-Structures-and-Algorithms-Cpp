/* C++ program to solve Accounts Merge problem
Problem Statement - https://leetcode.com/problems/accounts-merge/
*/

#include<bits/stdc++.h>
using namespace std;

int find_root(int u, vector<int>& parent){
    while(u!=parent[u]){
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}
    
void union_nodes(int u, int v, vector<int> &parent){
    parent[find_root(u, parent)] = find_root(v, parent);
}
    
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans; // stores the final answer
    vector<int> parent(10001);
    for(int i = 0; i<parent.size(); i++) parent[i] = i;
        
    map<string, string> em_name;
    map<string, int> em_id;
    int id = 0;
        
    for(int i = 0; i<accounts.size(); i++){
        string name(accounts[i][0]);
        for(int j = 1; j<accounts[i].size(); j++){
            string g = accounts[i][j];
            em_name[g] = name;
            if(em_id.find(g) == em_id.end()){
                em_id[g] = id;
                ++id;
            }
            union_nodes(em_id[accounts[i][1]], em_id[g], parent);
        }
    }
    map<int, vector<string>> temp2;
    for(auto x: em_name){
        string g(x.first);
        temp2[find_root(em_id[g], parent)].push_back(g);
    }
        
    for(auto x: temp2){
        vector<string> temp3(x.second);
        sort(temp3.begin(), temp3.end());
        temp3.insert(temp3.begin(), em_name[temp3[0]]);
        ans.push_back(temp3);
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	
	vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"},
	{"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
	{"Mary", "mary@mail.com"}};
	vector<vector<string>> ans = accountsMerge(accounts);
	
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<"  ";
		cout<<endl;
	}
	return 0;
}

