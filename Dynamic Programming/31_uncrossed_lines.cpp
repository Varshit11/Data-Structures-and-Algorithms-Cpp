/* C++ program to solve Uncrossed Lines problem
Problem Statement - https://leetcode.com/problems/uncrossed-lines/
*/

#include<bits/stdc++.h>
using namespace std;

int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    int mat[A.size()+1][B.size()+1];
    for(int i = 0; i<=A.size(); i++){
        for(int j = 0; j<=B.size(); j++){
            if(i == 0 || j == 0) mat[i][j] = 0;
            else if(A[i-1] == B[j-1]) mat[i][j] = 1+mat[i-1][j-1];
            else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }
    }
    return mat[A.size()][B.size()];
}

int main(){
	// code passed all test cases on leetcode, one test case is shown here for demonstration
	vector<int> A = {1,4,2};
	vector<int> B = {1,2,4};
	cout<<"The maximum number of connecting lines we can draw are "<<maxUncrossedLines(A,B)<<endl;
	return 0;
}
