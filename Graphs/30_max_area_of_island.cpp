/* C++ program to solve Max area of island problem
Problem Statement - https://leetcode.com/problems/max-area-of-island/
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& grid, int& d){
    if(row<0||row>=grid.size()||col<0||col>=grid[0].size()) return;
    if(grid[row][col] == 0) return;
    grid[row][col] = 0;
    d++;
    dfs(row+1, col, grid, d);
    dfs(row-1, col, grid, d);
    dfs(row, col+1, grid, d);
    dfs(row, col-1, grid, d);
}
    
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int ans = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j]){
                int temp = 0;
                dfs(i,j,grid, temp);
                ans = max(ans, temp);
            }
        }
    }
    return ans;
}
  
int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0},
	{0,1,1,0,1,0,0,0,0,0,0,0,0}, {0,1,0,0,1,1,0,0,1,0,1,0,0}, {0,1,0,0,1,1,0,0,1,1,1,0,0},
	{0,0,0,0,0,0,0,0,0,0,1,0,0}, {0,0,0,0,0,0,0,1,1,1,0,0,0}, {0,0,0,0,0,0,0,1,1,0,0,0,0}};
	
	cout<<"The maximum area of island is "<<maxAreaOfIsland(grid)<<endl;
	return 0;
}  

