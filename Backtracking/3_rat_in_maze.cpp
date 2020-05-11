/* C++ program to solve Rat in a Maze problem
Problem Statement - https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
*/

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>> &mat, int row, int col){
	if(row < 0 || row >= mat.size()) return false;
	if(col < 0 || col >= mat.size()) return false;
	if(mat[row][col] == 0) return false;
	return true;
}

bool rat_in_maze(vector<vector<int>> &new_mat, vector<vector<int>> &mat, int row, int col, char dir){
	if(row == mat.size()-1 && col == mat.size()-1 && mat[row][col] == 1) {
		new_mat[row][col] = 1;
		return true;
	}
	if(check(mat, row, col)){
		new_mat[row][col] = 1;
		if(dir != 'U' && rat_in_maze(new_mat, mat, row+1, col, 'D')) return true;
		if(dir != 'D' && rat_in_maze(new_mat, mat, row-1, col, 'U')) return true;
		if(dir != 'L' && rat_in_maze(new_mat, mat, row, col+1, 'R')) return true;
		if(dir != 'R' && rat_in_maze(new_mat, mat, row, col-1, 'L')) return true;
		new_mat[row][col] = 0;
		return false;
	}	
	return false;
}

int main(){
	vector<vector<int>> mat = {{1,0,1,1,1}, {1,1,1,0,1}, {1,0,0,1,1}, {1,0,0,1,0}, {1,0,0,1,1}};
	vector<vector<int>> new_mat(mat.size(), vector<int>(mat.size()));
	if(!rat_in_maze(new_mat, mat, 0, 0, 'L')) cout<<"There is no path for rat to get out of maze "<<endl;
	else{
		cout<<"The path for rat to get out of maze is "<<endl;
		for(int i = 0; i<new_mat.size(); i++){
			for(int j = 0; j<new_mat.size(); j++) {
				if(new_mat[i][j] == 1) cout<<new_mat[i][j]<<" ";
				else cout<<"  ";
			}
			cout<<endl;
		}
	}
	return 0;
}

