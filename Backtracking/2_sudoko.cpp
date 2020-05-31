/* C++ program for Sudoku
Problem Statement - https://www.geeksforgeeks.org/sudoku-backtracking-7/
*/

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>> &mat, int row, int col, int num){
	int i, j;
	for(i=0; i<mat.size(); i++) if(mat[i][col] == num) return false; // checking column
	for(i=0; i<mat.size(); i++) if(mat[row][i] == num) return false; // checking row
	// checking box..
	row -= row%3;
	col -= col%3;
	for(i=0;i<3;i++) for(j=0;j<3;j++) if(mat[i+row][j+col] == num) return false;
	return true;
}

bool find_unassigned(vector<vector<int>> &mat, int &row, int &col){
	for(row = 0; row<mat.size(); row++){
		for(col = 0; col<mat.size(); col++){
			if(mat[row][col] == 0){
				return true;
			}
		}
	}
	return false;
}

bool sudoko(vector<vector<int>> &mat){
	int row, col;
	if(!find_unassigned(mat, row, col)) return true;
	for(int i = 1; i<=9; i++){
		if(check(mat, row, col, i)){
			mat[row][col] = i;
			if(sudoko(mat)) return true;
			mat[row][col] = 0;
		}
	}
	return false;
}

int main(){
	vector<vector<int>> mat = {{3,0,6,5,0,8,4,0,0},{5,2,0,0,0,0,0,0,0}, {0,8,7,0,0,0,0,3,1}, {0,0,3,0,1,0,0,8,0},
	{9,0,0,8,6,3,0,0,5}, {0,5,0,0,9,0,6,0,0}, {1,3,0,0,0,0,2,5,0}, {0,0,0,0,0,0,0,7,4}, {0,0,5,2,0,6,3,0,0}};
	
	if(!sudoko(mat)) cout<<"Sudoko not possible "<<endl;
	else{
		cout<<"The sudoko is "<<endl;
		for(int i = 0; i<9;i++){
			for(int j = 0; j<9;j++) cout<<mat[i][j]<<" ";
			cout<<endl;
		}
	}
	return 0;
}

