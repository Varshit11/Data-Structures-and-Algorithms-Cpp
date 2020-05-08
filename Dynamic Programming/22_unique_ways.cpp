/* C++ program to solve Unique ways problem
Problem Statement - https://leetcode.com/problems/unique-paths/
*/

#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int mat[m][n], i, j;
    for(i=0;i<m;i++) mat[i][0] = 1;
    for(i=0;i<n;i++) mat[0][i] = 1;
    for(i=1;i<m;i++) for(j=1;j<n;j++) mat[i][j] = mat[i-1][j] + mat[i][j-1];
    return mat[m-1][n-1];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	int m = 7, n = 3;
	cout<<"The number of unique ways in a 7*3 matrix are "<<uniquePaths(m,n)<<endl;
	return 0;
}
