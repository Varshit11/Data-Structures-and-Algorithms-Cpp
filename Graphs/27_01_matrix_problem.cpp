/* C++ program to solve 01 matrix problem
Problem Statement - https://leetcode.com/problems/01-matrix/
*/
 
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
    queue<pair<int, int>> q;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            if(matrix[i][j] == 0){
                ans[i][j] = 0;
                q.push({i,j});
            }
        }
    }
        
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
    while(!q.empty()){
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        for(int i = 0; i<directions.size(); i++){
            int n_row = cur_row + directions[i][0];
            int n_col = cur_col + directions[i][1];
            if(n_row>=0 && n_row<matrix.size() && n_col>=0 && n_col<matrix[0].size()){
                if(ans[n_row][n_col] > ans[cur_row][cur_col]+1){
                    ans[n_row][n_col] = 1+ans[cur_row][cur_col];
                    q.push({n_row, n_col});
                }
            }
        }
    }
    return ans;
}
	
int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> matrix = {{0,0,0},{0,1,0}, {1,1,1}};
	vector<vector<int>> ans = updateMatrix(matrix);
	for(int i = 0; i<ans.size(); i++){
		for(int j = 0; j<ans[i].size(); j++)
			cout<<ans[i][j]<<" ";
		cout<<endl;
	}
	return 0;
} 
