/* C++ program to solve Matrix Chain Multiplication problem  using DP 
Problem Statement - https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
*/

#include<iostream>
using namespace std;

int matrix_chain_order(int*p, int N){
	int m[N][N];
	int i, j, k, l, q;
	for(int i = 0; i<N;i++) m[i][i] = 0;
	for (l = 2; l < N; l++) 
    {
        for (i = 1; i < N - l + 1; i++) 
        { 
            j = i + l - 1; 
            m[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) m[i][j] = q; 
            } 
        } 
    }
	return m[1][N - 1]; 
}

int main(){
	int p[4] = {1,2,3,4};
	cout<<"Minimum number of operations required are "<<matrix_chain_order(p, 4)<<endl;
	return 0;
}


