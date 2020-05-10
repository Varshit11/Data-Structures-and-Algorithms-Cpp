/* C++ program to solve N Queen Problem
Problem Statement - https://www.geeksforgeeks.org/c-program-for-n-queen-problem-backtracking-3/
*/

#include<iostream>
#include<vector>
using namespace std;

bool check(vector<vector<int>> &v, int row, int col){
	int i, j;
	for(i=0;i<col;i++) if(v[row][i]) return false;
	for(i=row, j=col; i>=0 && j>=0; i--, j--) if(v[i][j]) return false;
	for(i=row, j=col; i<v.size() && j>=0; i++, j--) if(v[i][j]) return false;
	return true;
}

bool N_queen(vector<vector<int>> &v, int col){
	if(col>=v.size()) return true;
	for(int i = 0; i<v.size(); i++){
		if(check(v, i, col)) {
			v[i][col] = 1;
			if(N_queen(v, col+1)) return true;
			v[i][col] = 0;
		}
	}
	return false;
}

int main(){
	vector<vector<int>> v = {{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
	if(N_queen(v, 0)){
		cout<<"The matrix will be "<<endl;
		for(int i = 0; i<v.size(); i++){
			for(int j = 0; j<v[i].size(); j++) cout<<v[i][j]<<" ";
			cout<<endl;
		}
	}
	else cout<<"There are no such arrangements "<<endl;
	return 0;
}

