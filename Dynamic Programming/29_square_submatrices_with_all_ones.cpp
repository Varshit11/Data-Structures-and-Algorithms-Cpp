/*  C++ program to Count Square Submatrices with All Ones
Problem Statement - https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

#include<iostream>
#include<vector>
using namespace std;

int min(int a, int b, int c){
    return a<b ? (a<c?a:c) : (b<c?b:c);
}
    
int countSquares(vector<vector<int>>& matrix) {
    if(matrix.size() == 0) return 0;
    int count = 0;
        
    for(int i = 0; i<matrix.size(); i++) if(matrix[i][0] == 1) count++;
    for(int i = 1; i<matrix[0].size(); i++) if(matrix[0][i] == 1) count++;
        
    for(int i = 1; i<matrix.size(); i++){
        for(int j = 1; j<matrix[0].size(); j++){
            if(matrix[i][j] > 0){
                matrix[i][j] = 1+min(matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]);
                count+= matrix[i][j];
            }
        }
    }
    return count;
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<vector<int>> matrix = {{0,1,1,1}, {1,1,1,1}, {0,1,1,1}};
	cout<<"The number of square submatrices with all ones are "<<countSquares(matrix)<<endl;
	return 0;
}

