/* C++ program to solve number of Enclaves problem 
Problem Statement - https://leetcode.com/problems/number-of-enclaves/
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &A, int row, int col, int& temp_ans, int& boundary){
	if(row<0 || row>= A.size() || col<0 || col>=A[0].size()) return;
    if((row == 0 || row == A.size()-1 || col == 0 || col == A[0].size()-1) && A[row][col] == 1){
        boundary = 1;
        temp_ans = 0;
    }
    if(A[row][col] == 0) return;
    A[row][col] = 0;
    if(boundary == 0) temp_ans++;
    dfs(A, row+1, col, temp_ans, boundary);
    dfs(A, row-1, col, temp_ans, boundary);
    dfs(A, row, col+1, temp_ans, boundary);
    dfs(A, row, col-1, temp_ans, boundary);
}
    
int numEnclaves(vector<vector<int>>& A) {
    int ans = 0;
    for(int i = 0; i<A.size(); i++){
        for(int j = 0; j<A[i].size(); j++){
            if(A[i][j] == 1){
                int temp_ans = 0;
                int boundary = 0;
                dfs(A, i, j, temp_ans, boundary);
                ans+= temp_ans;
            }
        }
    }
    return ans;
}
int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> A = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},
	{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},
	{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},
	{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
	cout<<numEnclaves(A)<<endl;
	return 0;
}
