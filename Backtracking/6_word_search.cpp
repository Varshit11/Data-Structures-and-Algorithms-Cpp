/* C++ program to solve Word Search problem
Problem Statement - https://leetcode.com/problems/word-search/
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool find(int row, int col, string word, vector<vector<char>> &board){
    if(word.length() == 0) return true;
    if(row < 0 || col < 0 || row == board.size() || col == board[0].size() || board[row][col] != word[0])
        return false;
    bool ret = false;
    board[row][col] = '@';
    vector<vector<int>> temp = {{0,1}, {1,0}, {-1, 0}, {0,-1}};
    for(int k = 0; k<temp.size(); k++){
        string temp2(word.begin()+1, word.end());
        ret = find(row+temp[k][0], col+temp[k][1], temp2, board);
        if(ret) break;
    }
    board[row][col] = word[0];
    return ret;   
}
    
bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(find(i, j, word, board)) return true;
        }
    }
    return false;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	string word("ABCCED");
	if(exist(board, word)) cout<<"There exists the word in the matrix"<<endl;
	else cout<<"There does not exists the word in the matrix"<<endl;
	return 0;
}

