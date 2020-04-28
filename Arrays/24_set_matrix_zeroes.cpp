/* C++ program to solve set matrix zero problem 
Problem Statement - https://leetcode.com/problems/set-matrix-zeroes/
*/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), i, j;
    bool row_flag = false, col_flag = false;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(i ==0 && matrix[i][j] == 0)
                row_flag = true;
            if(j == 0 && matrix[i][j] == 0)
                col_flag = true;
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
        
    for(i=1;i<m;i++){
        for(j=1;j<n;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
        
    if(row_flag){
        for(j=0;j<n;j++)
            matrix[0][j] = 0;
    }
        
    if(col_flag){
        for(i=0;i<m;i++)
            matrix[i][0] = 0;
    }
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> matrix = {{1,1,1}, {1,0,1}, {1,1,1}};
	setZeroes(matrix);
	for(int i = 0; i<matrix.size();i++){
		for(int j = 0; j<matrix[i].size();j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

