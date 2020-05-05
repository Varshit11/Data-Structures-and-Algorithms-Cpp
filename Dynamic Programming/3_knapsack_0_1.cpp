/* C++ program to solve the 0/1 knapsack problem using recursion and dynamic Programming */

#include<iostream>
using namespace std;

// time complexity of recursive solution is O(2^h) where h is max(val.size(), W)
int knapsack_recursive(int* val, int* wt, int W, int N){ // N is the size of the val and wt array
	if(W <= 0 || N == 0) return 0;
	if(wt[N-1] > W) return knapsack_recursive(val, wt, W, N-1);
	else return max(val[N-1]+knapsack_recursive(val, wt, W-wt[N-1], N-1), knapsack_recursive(val, wt, W, N-1));
}

// time complexity of DP approach is O(W*N) and space complexity is O(W*N)
int knapsack_DP(int* val, int* wt, int W, int N){
	int mat[N+1][W+1];
	for(int i = 0; i<=N; i++){
		for(int j = 0; j<=W; j++){
			if(i == 0 || j == 0) mat[i][j] = 0;
			else if(wt[i-1] <= j) mat[i][j] = max(val[i-1]+mat[i-1][j-wt[i-1]], mat[i-1][j]);
			else mat[i][j] = mat[i-1][j];
		}
	}
	return mat[N][W];
}

int main(){
	int val[3] = {60, 100, 120}, wt[3] = {10, 20, 30}, N = 3, W = 50;
	int recur = knapsack_recursive(val, wt, W, N);
	int dp = knapsack_DP(val, wt, W, N);
	cout<<"The maximum value we can get by filling the bag using recursion is "<<recur<<endl;
	cout<<"The maximum value we can  get by filling the bag using DP is "<<dp<<endl;
	return 0;
}

