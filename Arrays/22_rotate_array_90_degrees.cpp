/* C++ program to rotate matrix by 90 degrees 
Problem Statement - https://leetcode.com/problems/rotate-image/
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int* p, int* q){
        int temp = *p;
        *p = *q;
        *q = temp;
}
void rotate(vector<vector<int>>& matrix) {
    int i, j, N = matrix.size();
    // finding transpose
    for(i=0;i<N; i++)
        for(j=i+1;j<N;j++)
            swap(&matrix[i][j], &matrix[j][i]);

	// now reversing every row of the transposed matrix
    for(i=0;i<N;i++)
        for(j=0;j<N/2;j++)
            swap(&matrix[i][j], &matrix[i][N-1-j]);
}

int main(){
	vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
	rotate(matrix);
	for(int i = 0; i<matrix.size(); i++){
		for(int j = 0; j<matrix.size(); j++)
			cout<<matrix[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}

