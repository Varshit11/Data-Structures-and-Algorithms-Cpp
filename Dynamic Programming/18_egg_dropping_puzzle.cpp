/* C++ program to solve Egg dropping puzzle using recursion and bottom up DP
*/

#include<iostream>
using namespace std;

int egg_dropping_recursion(int N, int K){
	if(K == 0 || K == 1) return K;
	if(N == 1) return K;
	int best = INT_MAX;
	for(int x = 1; x<=K;x++) {
		best = min(best, 1 + max(egg_dropping_recursion(N-1, x-1), egg_dropping_recursion(N, K-x)));
	}
	return best;
}

int egg_dropping_bottom_up(int N, int K){
	int mat[N+1][K+1], i, j, x;
	for(i = 0; i<= N; i++){
		mat[i][0] = 0;
		mat[i][1] = 1;
	}
	for(i=0; i<=K; i++){
		mat[0][i] = INT_MAX;
		mat[1][i] = i;
	}
	for(i=2; i<=N; i++){
		for(j=2; j<=K; j++){
			mat[i][j] = INT_MAX;
			for(x=1; x<=j; x++) mat[i][j] = min(mat[i][j], 1+max(mat[i-1][x-1], mat[i][j-x]));
		}
	}
	return mat[N][K];
}

int main(){
	int N = 2, K = 10;
	cout<<"Using recursion, Min no. of trials with 2 eggs and 10 floors are "<<egg_dropping_recursion(N, K)<<endl;
	cout<<"Using bottom up DP, Min no. of trials with 2 eggs and 10 floors are "<<egg_dropping_bottom_up(N, K)<<endl;
	return 0;
}

