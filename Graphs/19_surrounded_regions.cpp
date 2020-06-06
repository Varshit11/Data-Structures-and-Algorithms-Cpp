/* C++ program to solve surrounded regions problem
Problem Statement - https://leetcode.com/problems/surrounded-regions/
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& board, int row, int col){
    if(row<0||col<0||row>=board.size()||col>=board[0].size()) return;
    if(board[row][col] == 'X' || board[row][col] == '@') return;
    board[row][col] = '@';
    dfs(board, row+1, col);
    dfs(board, row-1, col);
    dfs(board, row, col+1);
    dfs(board, row, col-1);
}
    
void solve(vector<vector<char>>& board) {
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 'O'){
                if(i ==0||j == 0|| i==board.size()-1|| j == board[0].size()-1)
                    dfs(board, i, j);
            }
        }
    }
        
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[i].size(); j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            else if(board[i][j] == '@') board[i][j] = 'O';
        }
    }
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, 
								{'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
	solve(board);
	
	cout<<"The new matrix is "<<endl;
	for(int i = 0; i<board.size(); i++){
		for(int j = 0; j<board[i].size(); j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
