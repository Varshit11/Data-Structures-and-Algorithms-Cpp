/* C++ program to solve rotting oranges problem
Problem Statement - https://leetcode.com/problems/rotting-oranges/
*/

#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if(grid.size() == 0) return 0;
    queue<pair<int, int>> q;
    int time = -1, num_fresh = 0;
    for(int i = 0; i<grid.size(); i++){
        for(int j = 0; j<grid[i].size(); j++){
            if(grid[i][j] == 2) q.push(make_pair(i,j));
            else if(grid[i][j] == 1) num_fresh++;
        }
    }
    q.push(make_pair(-1, -1)); // to signify the end of one level
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()){
        pair<int, int> temp = q.front();
        q.pop();
        if(temp.first == -1){
            time++;
            if(!q.empty()) q.push(make_pair(-1,-1));
        }
        else{
            for(int i = 0; i<directions.size(); i++){
                int n_row = temp.first + directions[i][0];
                int n_col = temp.second + directions[i][1];
                if(n_row >= 0 && n_row <grid.size() && n_col >= 0 && n_col <grid[0].size()){
                    if(grid[n_row][n_col] == 1){
                        grid[n_row][n_col] = 2;
                        num_fresh--;
                        q.push(make_pair(n_row, n_col));
                    }
                }
            }
        }
    }
    return num_fresh == 0 ? time : -1;
}
    
int main(){
	vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
	cout<<"The time required is "<<orangesRotting(grid)<<endl;
	return 0;
}

