/* C++ program to count number of islands
Problem Statement - https://leetcode.com/problems/number-of-islands/
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<char>> &grid, int row, int col){
    grid[row][col] = '0';
    if(row+1<grid.size() && grid[row+1][col] == '1') dfs(grid, row+1, col);
    if(row-1>=0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
    if(col+1<grid[0].size() && grid[row][col+1] == '1') dfs(grid, row, col+1);
    if(col-1>=0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
}
    
int numIslands(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    int num_islands = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[0].size(); j++){
            if(grid[i][j] == '1'){
                num_islands++;
                dfs(grid, i, j);
            }
        }
    }
    return num_islands;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
	cout<<"The number of islands in this grid are "<<numIslands(grid)<<endl;
	return 0;
}

