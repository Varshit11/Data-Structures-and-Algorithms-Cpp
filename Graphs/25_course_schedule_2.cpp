/* C++ program to solve course schedule 2 problem
Problem Statement - https://leetcode.com/problems/course-schedule-ii/
*/

#include<bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<bool> &visited, stack<int>& st, vector<int> adj_list[], vector<bool>& cur_stack){
    if(!visited[u]){
        visited[u] = true;
        cur_stack[u] = true;
        for(int i = 0; i<adj_list[u].size(); i++){
            int temp = adj_list[u][i];
            if(!visited[temp] && !dfs(temp, visited, st, adj_list, cur_stack)) return false;
            else if(cur_stack[temp]) return false;
        }
    }
    cur_stack[u] = false;
    st.push(u);
    return true;
}
    
vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
    vector<int> adj_list[numCourses];
    for(int i = 0; i<pre.size(); i++){
        adj_list[pre[i][1]].push_back(pre[i][0]);
    }
    vector<int> ans;
    stack<int> st;
    vector<bool> visited(numCourses, false);
    vector<bool> cur_stack(numCourses, false);
    for(int i = 0; i<numCourses; i++){
        if(!visited[i])
            if(!dfs(i, visited, st, adj_list, cur_stack)) return ans;
    }
        
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int numCourses = 4;
	vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
	vector<int> ans = findOrder(numCourses, prerequisites);
	if(ans.size() == 0) cout<<"There is cycle in graph so no schedule possible "<<endl;
	else{
		cout<<"One of the possible schedule is "<<endl;
		for(int i = 0; i<ans.size(); i++)
			cout<<ans[i]<<" ";
	}
	return 0;
}

