/* C++ program to solve Subset Sum problem
Problem Statement - https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
*/

#include<iostream>
using namespace std;

bool subset_sum_recursive(int* set, int N, int sum){
	if(N == 0 && sum > 0) return false;
	else if(sum == 0) return true;
	else if(set[N-1] > sum) return subset_sum_recursive(set, N-1, sum);
	else return (subset_sum_recursive(set, N-1, sum-set[N-1]) || subset_sum_recursive(set, N-1, sum));
}

bool subset_sum_DP(int* set, int N, int sum){
	bool m[N+1][sum+1];
	for(int i = 0; i<=N; i++){
		for(int j = 0; j<=sum; j++){
			if(i == 0 && j>0) m[i][j] = false;
			else if(j == 0) m[i][j] = true;
			else if(set[i-1] > j) m[i][j] = m[i-1][j];
			else m[i][j] = m[i-1][j-set[i-1]] || m[i-1][j];
		}
	}
	return m[N][sum];
}

int main(){
	int set[] = {3, 34, 4, 12, 5, 2};
	int N = sizeof(set)/sizeof(set[0]), sum = 9;
	bool recur = subset_sum_recursive(set, N, sum);
	bool dp = subset_sum_DP(set, N, sum);
	if(recur) cout<<"There is a subset whose sum is equal to 9 "<<endl;
	else cout<<"There is no subset which sums to 9 "<<endl;
	if(dp) cout<<"There is a subset whose sum is equal to 9 "<<endl;
	else cout<<"There is no subset which sums to 9 "<<endl;
	return 0;
}

