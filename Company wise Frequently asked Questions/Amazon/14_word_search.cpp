/* C++ program to solve word search problem
Problem Statement - https://leetcode.com/problems/word-search/
*/

#include<bits/stdc++.h>
using namespace std;

bool exist_util(vector<vector<char>> &board, string word, int row, int col){
    if(word.length() == 0) return true;
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;
    if(board[row][col] != word[0]) return false;
    bool ret = false;
    board[row][col] = '@';
    vector<vector<int>> directions = {{1,0}, {-1, 0}, {0,1}, {0,-1}};
    for(int i = 0; i<directions.size(); i++){
        string temp(word.begin() +1, word.end());
        ret = exist_util(board, temp, row+directions[i][0], col+directions[i][1]);
        if(ret) break;
    }
    board[row][col] = word[0];
    return ret;
}
    
bool exist(vector<vector<char>>& board, string word) {
    if(word.length() == 0) return false;
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(exist_util(board, word, i, j)) return true;
        }
    }
    return false;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	string word = "ABCCED";
	if(exist(board, word)) cout<<"word is present in the matrix"<<endl;
	else cout<<"Word is not present in the matrix"<<endl;
	return 0;
}

